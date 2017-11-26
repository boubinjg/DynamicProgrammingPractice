#include<vector>
#include<iostream>
std::vector<int> set{1,3,5};
int CATN(int n){
	int combs = 0;
	if(n == 0)
		return 1;
	for(int i = 0; i<set.size(); i++){
		if(n == 0)
			combs += 1;
		else if(set[i] <= n){
			combs += CATN(n-set[i]);
		} 
	}
	return combs;
}

/* F(i) = the number of combinations of set s that add up to i
 * Recurrence: f(i) = sum of f[i-set[j]] where i > j and 0<j<size of set
 * Boundary condition: f[i] == 1 if i == 0                      
 * Running time: O(set.size * n)
 */

int CATNDP(int n){
	std::vector<int> f(n+1, 0);	

	for(int i = 0; i<=n; i++){
		int combs = 0;
		for(int j = 0; j<set.size(); j++) {
			if((i - set[j]) == 0) {
				combs += 1;
			}
			else if((i - set[j]) > 0) {
				combs += f[i - set[j]];
			}
		}
		f[i] = combs;
	}
	return f[n];
}
int main(){
	std::cout<<CATN(6)<<std::endl;
	std::cout<<CATNDP(6)<<std::endl;
	return 0;
}
