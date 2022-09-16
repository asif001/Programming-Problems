// Problem: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int right = -1;
        int left = -1;
        int min_seen = INT_MAX;
        int max_seen = INT_MIN;
        
        for(int i = 0;i < nums.size();i++){
            max_seen = max(nums[i], max_seen);
            if(nums[i] < max_seen){
                right = i;
            }
        }
        
        for(int i = nums.size()-1;i >= 0;i--){
            min_seen = min(nums[i], min_seen);
            if(nums[i] > min_seen){
                left = i;
            }
        }
        
        int res = right - left + 1;
        
        return res > 1 ? res : 0;
    }
};
