// Problem: https://leetcode.com/problems/climbing-stairs/

// Recursive

class Solution {
public:
    int dp[46] = {0};
    
    int climbStairs(int n) {
        if(n == 0){
            return 1;
        }
        
        if(n == 1){
            return 1;
        }
        
        if(dp[n] != 0){
            return dp[n];
        }
        
        dp[n] = climbStairs(n-1) + climbStairs(n-2);
        
        return dp[n];
    }
};

// Iterative

class Solution {
public:
    int climbStairs(int n) {
        int dp[46] = {0};
    
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2;i <= n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
