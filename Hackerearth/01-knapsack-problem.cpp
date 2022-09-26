// Problem: https://www.hackerearth.com/problem/algorithm/01-knapsack-problem-5a88b815/

#include <iostream>
#include <vector>
using namespace std;

int knapSack(vector<int>& v, vector<int>& w, vector<vector<int>>& dp, int n, int itemNo, int c){
	if(itemNo == n){
		return dp[itemNo][c] = 0;
	}

	if(dp[itemNo][c] != -1){
		return dp[itemNo][c];
	}

	int value1 = 0, value2 = 0;
	if(w[itemNo] <= c){
		value1 = v[itemNo] + knapSack(v, w, dp, n, itemNo + 1, c - w[itemNo]);
	}

	value2 = knapSack(v, w, dp, n, itemNo + 1, c);

	return dp[itemNo][c] = max(value1, value2);
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

	cout << knapSack(v, w, dp, n, 0, c) << endl;

	return 0;
}
