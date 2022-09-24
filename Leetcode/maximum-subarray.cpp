// Problem: https://leetcode.com/problems/maximum-subarray/

// Divide and conquer (nlgn)
class Solution {
public:
    int maxCrossSum(vector<int>& nums, int l, int mid, int r){
        int maxLeftSum = INT_MIN;
        int leftSum =0;
        for(int i = mid;i >= l;i--){
            leftSum += nums[i];
            maxLeftSum = max(maxLeftSum, leftSum);
        }
        
        int maxRightSum = INT_MIN;
        int rightSum = 0;
        for(int i = mid;i <= r;i++){
            rightSum += nums[i];
            maxRightSum = max(maxRightSum, rightSum);
        }
        
        return max(maxLeftSum+maxRightSum-nums[mid],max(maxLeftSum,maxRightSum));
    }
    
    int maxSubArraySum(vector<int>& nums, int l, int r){
        if(l == r){
            return nums[l];
        }
        
        if(l > r){
            return INT_MIN;
        }
        
        int mid = (r-l)/2+l;
        
        return max(maxSubArraySum(nums,l,mid),max(maxSubArraySum(nums,mid+1,r),maxCrossSum(nums,l,mid,r)));
    }
    
    int maxSubArray(vector<int>& nums) {
        int n = (int)nums.size();
        
        return maxSubArraySum(nums, 0, n-1);
    }
};

// Kadane

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = (int)nums.size();
        int currSum = 0;
        int maxSum = INT_MIN;
        
        for(int i = 0;i < n; i++){
            currSum += nums[i];
            maxSum = max(currSum, maxSum);
            
            if(currSum < 0){
                currSum = 0;
            }
        }
        
        return maxSum;
    }
};
