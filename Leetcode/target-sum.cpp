// Problem: https://leetcode.com/problems/target-sum/

// O(n*2001)
class Solution {
public:
    int findWays(vector<int>& nums, int (&dp)[20][2001], int i, int target){
        if(i == 0){
            return (target - nums[0] == 0 ? 1 : 0) + (target + nums[0] == 0 ? 1 : 0);
        }
        
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        
        int res1 = findWays(nums, dp, i-1, target-nums[i] >= 0 ? target-nums[i] : nums[i]-target);
        int res2 = findWays(nums, dp, i-1, target+nums[i]);

        return dp[i][target] = res1+res2;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int dp[20][2001];
        int n = (int)nums.size();
        
        for(int i = 0;i < 20;i++){
            for(int j = 0;j < 2001;j++){
                dp[i][j] = -1;
            }
        }
        
        return findWays(nums, dp, n-1, target >= 0 ? target : -1*target);
    }
};

//O(n*1001)
class Solution {
public:
    int findWays(vector<int>& nums, int (&dp)[20][1001], int i, int target){
        if(i == 0){
            
            return (target == 0 && nums[0] != 0 ? 1 : 0) + (target == nums[0] ? 1 : 0) + (target == -1*nums[0] ? 1 : 0);
        }
        
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        
        int res1 = 0, res2 = 0;
        if(nums[i] <= target){
            res1 = findWays(nums, dp, i-1, target-nums[i]);
        }
        
        res2 = findWays(nums, dp, i-1, target);

        return dp[i][target] = res1+res2;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int dp[20][1001];
        int n = (int)nums.size();
        
        for(int i = 0;i < 20;i++){
            for(int j = 0;j < 1001;j++){
                dp[i][j] = -1;
            }
        }
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum < 0 || target + sum < 0 || (target+sum)%2 == 1){
            return 0;
        }
        
        return findWays(nums, dp, n-1, (target+sum)/2);
    }
};
