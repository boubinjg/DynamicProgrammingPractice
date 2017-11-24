#include<iostream>
#include<vector>
#include<climits>

/* f(i,j) = the number of coins it takes to make change totalling the amount i given option coin j
 * Recurrence: f(i,j) = min( f(i, j-1), 1 + f(i-val(j), j)) 
 * Boundary conditions: if j = 0,        f[i,j] = 1 + f[i-val(j), j)), 
 * 	                if i-val(j) < 0, f[i,j] = f[i][j-1] 
 *
 * Time complexity: O(n * v), n = num of coins, v = value, pseudopolynomial time
 */

std::vector<int> coins{1,3,4,5,10,15};
int coinChange(int value){
	if(value <= 0)
		return 0;
	int min = INT_MAX;
	for(auto c : coins){
		if(c <= value){
			int curMin = coinChange(value-c);
			if(min > curMin){
				min = curMin;
			}
		}
	}
	return min+1;
}
int coinChangeDP(int value){
	std::vector<std::vector<int>> f;
	for(int i = 0; i<value+1; i++){
		std::vector<int> v;
		for(int j = 0; j<coins.size(); j++){
			v.push_back(0);
		}
		f.push_back(v);
	}
	
	for(int i = 1; i<=value; i++){
		for(int j = 0; j<coins.size(); j++){
			if(i-coins[j] < 0)
				f[i][j] = f[i][j-1];
			else if(j == 0)
				f[i][j] = 1 + f[i-coins[j]][j];
			else	
				f[i][j] = std::min(f[i][j-1], 1 + f[i-coins[j]][j]);
			std::cout<<f[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return f[value][coins.size()-1];
}
int main(){
	std::cout<<coinChange(15)<<" "<<coinChange(7)<<" "<<coinChange(21)<<std::endl;
	std::cout<<coinChangeDP(7)<<std::endl;
	return 0;
}
