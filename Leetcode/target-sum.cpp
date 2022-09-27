// Problem: https://leetcode.com/problems/target-sum/

// O(n*2001)
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

//O(n*1001)

class Solution {
public:
    int findWays(vector<int>& nums, int (&dp)[20][1001], int n, int currIndex, int target){
        if(n == currIndex){
            return target == 0 ? 1 : 0;
        }
        
        if(dp[currIndex][target] != -1){
            return dp[currIndex][target];
        }
        
        int res1 = 0, res2 = 0;
        if(nums[currIndex] <= target)
        res1 = findWays(nums, dp, n, currIndex+1, target-nums[currIndex]);
        
        res2 = findWays(nums, dp, n, currIndex+1, target);

        return dp[currIndex][target] = res1+res2;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int dp[20][1001];
        
        for(int i = 0;i < 20;i++){
            for(int j = 0;j < 1001;j++){
                dp[i][j] = -1;
            }
        }
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        target = target+sum;
        
        if(target < 0 || sum < 0 || target%2 == 1){
            return 0;
        }
        
        return findWays(nums, dp, (int)nums.size(), 0, target>>1);
    }
};
