#include<iostream>
#include<vector>
#include<climits>

/* f(i,j) = whether there is a subset from 0..i that equals j
 * Recurrence: f(i,j) = if set[i] < j, 0, else f[i-1][j-set[i]] || f[i-1][j]  
 * Boundary conditions: if j == 0, return true 
 *
 * Time complexity: O(n*value), pseudopolynomial
 */

std::vector<int> set{3,34,4,12,5,2};
bool subsetSum(int value, int index){
	for(int i = index; i<set.size(); i++){
		bool sumToVal = false;
		if(value - set[i] == 0){
			sumToVal = true;
		} else {
			sumToVal = subsetSum(value-set[i], index + 1) || 
				   subsetSum(value, index + 1);
		}
		return sumToVal;
	}
}
int subsetSumDP(int value){
	std::vector<std::vector<bool>> f;
	
	for(int i = 0; i<set.size(); i++){
		std::vector<bool> v(value+1, 0);
		f.push_back(v);
		std::cout<<v.size()<<std::endl;
	}
	for(int i = 0; i<set.size(); i++)
		f[0][i] = 1;
	
	for(int i = 1; i<set.size(); i++) {
		for(int j = 1; j<=value; j++){
			if(set[i-1] > i)
				f[i][j] = f[i-1][j];
			else if(j >= set[i-1])
				f[i][j] = f[i][j-set[i]] || f[i-1][j]; 
		}
	}
	return f[set.size()-1][value];
}
int main(){
	std::cout<<subsetSum(9, 0)<<std::endl;
	std::cout<<subsetSumDP(9)<<std::endl;
	return 0;
}
