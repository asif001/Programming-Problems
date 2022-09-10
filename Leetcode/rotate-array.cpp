// Problem: https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void reverseArray(vector<int>& nums, int low, int high){
        while(low < high){
            int temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            low++;
            high--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        
        reverseArray(nums, 0, n-k-1);
        reverseArray(nums, n-k, n-1);
        reverseArray(nums, 0, n-1);
    }
};
