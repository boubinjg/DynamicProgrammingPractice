#include<vector>
#include<iostream>
std::vector<int> v{-1,11,12,1,2,3,4,0,5,1,6};
int lis(int pos){
	int max = 1;
	for(int i = pos+1; i<v.size(); i++){
		if(v[i] > v[pos]){
			int curMax = 1 + lis(i);
			if(curMax > max)
				max = curMax;
		} 	
	}
	return max;
}

/* F(i) = Starting at position i, what is the longest inscreasing subsequence
 * Recurrence: f(i) = max(f(j) + 1) for all j where i<j and v[i] < v[v] 
 * Boundary condition: f[i] == 0 iff i>v.size   
 *                             1 iff i == j
 * Running time: O(n^2)
 */

int lisDP(){
	std::vector<int> f(v.size(), 1);	

	for(int i = v.size()-1; i>=0; i--){
		int max = 1;
		for(int j = i+1; j<v.size(); j++){
			if(v[i] < v[j]){
				int curMax = 1 + f[j];
				if(curMax > max){
					max = curMax;
				}
			}
		}
		f[i] = max;
	}
	return f[0];
}
int main(){
	int max = 0;
	for(int i = 0; i<v.size(); i++){
		int curMax = lis(i);
		if(curMax > max)
			max = curMax;
	}
	std::cout<<max<<std::endl;
	std::cout<<lisDP()<<std::endl;
	return 0;
}
