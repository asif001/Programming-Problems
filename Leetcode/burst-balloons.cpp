// Problem: https://leetcode.com/problems/burst-balloons/

class Solution {
public:
    int burstBallons(vector<vector<int>>& dp, vector<int>& nums, int l, int r){
        if(l > r){
            return 0;
        }
        
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        
        int maxCoinsCollected = 0;
        for(int i=l;i<=r;i++){
            int coinsCollected = 0;
            coinsCollected += burstBallons(dp, nums,l,i-1);
            coinsCollected += burstBallons(dp, nums,i+1,r);
            coinsCollected += nums[l-1]*nums[i]*nums[r+1];
            maxCoinsCollected = max(maxCoinsCollected, coinsCollected);
        }
        
        return dp[l][r] = maxCoinsCollected;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        vector<vector<int>> dp((int)nums.size(), vector<int>((int)nums.size(), -1));
        
        return burstBallons(dp, nums, 1, (int)nums.size()-2);
        
        return 0;
    }
};
