// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int* dp = new int[prices.size()];
        int profit = -prices[0];
        dp[0] = -prices[0];
        
        for(int i = 1;i < prices.size();i++){
            dp[i] = prices[i] - min(prices[i-1], prices[i-1] - dp[i-1]);
            profit = max(profit, dp[i]);
        }
        
        return profit > 0 ? profit : 0;
    }
};
