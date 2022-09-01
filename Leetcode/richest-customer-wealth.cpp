// Problem: https://leetcode.com/problems/richest-customer-wealth/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maximum = 0;
        
        for(auto account : accounts){
            maximum = max(maximum, accumulate(account.begin(), account.end(), 0));
        }
        
        return maximum;
    }
};
