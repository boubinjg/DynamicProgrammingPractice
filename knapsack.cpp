#include<vector>
#include<string>
#include<iostream>
struct knapsack{
	int W, V;
};

std::vector<knapsack> sack{{1,60},{2,100},{3,120}};
int knapsack(int initWeight, int index){
	int max = 0;
	for(int i = index; i < sack.size(); i++){
		int curMax = 0;
		if(sack[i].W <= initWeight){
			curMax = std::max(sack[i].V + knapsack(initWeight-sack[i].W, i+1), 		
					  knapsack(initWeight, i+1));	
		}
		if(curMax > max)
			max = curMax;
	}
	return max;
}

/* F(i,j) = the max value the knapsack can hold considering value 1..i and adding to at most weight j
 * Recurrence: f(i,j) = {if wi > j, f[i][j] = max( f[i-1][j], v[i] + f[i-1][j-wi]
 *                       else       f[i][j] = f[i-1][j] 
 * Boundary condition: if i < 0, f[i][j] = 0
 * 
 * Running time: O(n * w): where n is the number of elements in the knapsack, and w is the init weight
 * This algorithm's running time is deceptively bad, because it's pseudopolynomial. The knapsack problem is
 * np-hard, but is weak-np because it has a pseudopolynomial complexity
 */


//this code loops pretty bad but it was written late at night so forgive me
int knapsackDP(int initWeight){
	std::vector<std::vector<int>> f;
	for(int i = 0; i<=sack.size(); i++){
		std::vector<int> temp;
		for(int j = 0; j<=initWeight+1; j++)
			temp.push_back(0);
		f.push_back(temp);
	}
	for(int i = 0; i<sack.size(); i++){
		for(int j = 0; j<=initWeight; j++){
			if(sack[i].W <= j) {
				if(i > 0) {
					f[i][j] = std::max( sack[i].V + f[i-1][j-sack[i].W], 
					 		    f[i-1][j]);
				} else {
					f[i][j] = sack[i].V;
				}
			} else {
				if(i < 1) {
					f[i][j] = 0;
				} else {
					f[i][j] = f[i-1][j];
				}
			}
			std::cout<<f[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return f[sack.size()-1][initWeight];
}
int main(){
	std::cout<<knapsack(5, 0)<<std::endl;
	std::cout<<knapsackDP(5)<<std::endl;
	return 0;
}
