// Problem: https://www.hackerearth.com/problem/algorithm/01-knapsack-problem-5a88b815/

#include <iostream>
#include <vector>
using namespace std;

int knapSack(vector<int>& v, vector<int>& w, vector<vector<int>>& dp, int i, int c){
	if(i < 0){
		return 0;
	}

	if(dp[i][c] != -1){
		return dp[i][c];
	}

	int value1 = 0, value2 = 0;
	if(w[i] <= c){
		value1 = v[i] + knapSack(v, w, dp, i-1, c - w[i]);
	}

	value2 = knapSack(v, w, dp, i-1, c);

	return dp[i][c] = max(value1, value2);
}


int main() {
	int n, c;
	cin >> n >> c;
	
	vector<int> v(n), w(n);

	for(int i = 0;i < n;i++){
		cin >> v[i];
	}
	
	for(int i = 0;i < n;i++){
		cin >> w[i];
	}

	vector<vector<int>> dp(n+1, vector<int>(c+1, -1));

	cout << knapSack(v, w, dp, n-1, c) << endl;

	return 0;
}
