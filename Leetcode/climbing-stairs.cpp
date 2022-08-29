// Problem: https://leetcode.com/problems/climbing-stairs/

// Recursive dp

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

// Iterative dp

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

// Fibonocci

class Solution {
public:
    int climbStairs(int n) {
        int firstNumber = 1;
        int secondNumber = 1;
        
        for(int i = 2; i <= n; i++){
            int tempNumber = secondNumber;
            secondNumber = firstNumber + secondNumber;
            firstNumber = tempNumber;
        }
        
        return secondNumber;
    }
};
