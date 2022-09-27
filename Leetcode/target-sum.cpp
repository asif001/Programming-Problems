// Problem: https://leetcode.com/problems/target-sum/

class Solution {
public:
    int findWays(vector<int>& nums, int (&dp)[20][2001], int n, int currIndex, int target){
        if(n == currIndex){
            return target == 0 ? 1 : 0;
        }
        
        if(dp[currIndex][target] != -1){
            return dp[currIndex][target];
        }
        
        int res1 = findWays(nums, dp, n, currIndex+1, target-nums[currIndex] >= 0 ? target-nums[currIndex] : nums[currIndex]-target);
        int res2 = findWays(nums, dp, n, currIndex+1, target+nums[currIndex]);

        return dp[currIndex][target] = res1+res2;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int dp[20][2001];
        
        for(int i = 0;i < 20;i++){
            for(int j = 0;j < 2001;j++){
                dp[i][j] = -1;
            }
        }
        
        return findWays(nums, dp, (int)nums.size(), 0, target >= 0 ? target : -1*target);
    }
};
