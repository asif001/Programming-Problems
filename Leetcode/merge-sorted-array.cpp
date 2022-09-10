// Problem: https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m+n;
        
        while(m > 0 && n > 0){
            if(nums1[m-1] >= nums2[n-1]){
                nums1[idx-1] = nums1[m-1];
                m = m-1;
            }else{
                nums1[idx-1] = nums2[n-1];
                n=n-1;
            }
            
            idx=idx-1;
        }
        
        while(n > 0){
            nums1[idx-1] = nums2[n-1];
            n=n-1;
            idx=idx-1;
        }
    }
};
