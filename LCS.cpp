#include<vector>
#include<string>
#include<iostream>
std::string s1 = "ALCLLXBC", s2 = "XAXXBXXC";
int LCS(int  pos1, int pos2){
	int max = 0;
	if(pos2 >= s2.size())
		return 0;
	for(int i = pos1; i<s1.size(); i++) {
		//std::cout<<s1[i]<<" "<<s2[pos2]<<std::endl;
		int curMax = 0;
		if(s1[i] == s2[pos2]) {
			curMax = 1 + LCS(i + 1, pos2+1);
		} else {
			curMax += std::max( LCS(i, pos2+1), LCS(i+1, pos2) );
		}
		if(curMax > max)
			max = curMax;
	}
	return max;
}

/* F(i,j) = the longest common subsequence between strings s1i..s1n and s2j..s2n
 * Recurrence: f(i,j) = {if s1[i] == s2[j] f[i+1][j+1] + 1
			{else max( f[i+1][j], f[i][j+1]
 * Boundary condition: if i>s1.size or j>s2.size: f[i][j] = 0
 * Running time: O(s1 * s2): pseodupoly
 */

int LCSDP(){
	std::vector<std::vector<int>> f;
	for(int i = 0; i<s1.length()+1; i++){
		std::vector<int> temp;
		for(int j = 0; j<s2.length()+1; j++)
			temp.push_back(0);
		f.push_back(temp);
	}
	for(int i = s1.length()-1; i>=0; i--){
		for(int j = s2.length()-1; j>=0; j--){
			if(s1[i] == s2[j]){
				f[i][j] = 1 + f[i+1][j+1];
			} else {
				f[i][j] = std::max(f[i+1][j], f[i][j+1]);
			}
		}
	}
	return f[0][0];
}
int main(){
	std::cout<<LCS(0, 0)<<std::endl;
	std::cout<<LCSDP()<<std::endl;
	return 0;
}
