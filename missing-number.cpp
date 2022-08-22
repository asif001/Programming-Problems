//Problem: https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (int)nums.size() + 1;
        int sum = (n * n - n)/2;
        
        for(int i = 0;i < n-1;i++){
            sum = sum - nums[i];
        }
        
        return sum;
    }
};
