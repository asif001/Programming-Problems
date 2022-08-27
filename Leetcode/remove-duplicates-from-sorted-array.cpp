// Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        
        for(int i = 0;i < (int)nums.size();i++){
            int currNumber = nums[i];
            int nextDiffNumIndex = i+1;
            
            while(nextDiffNumIndex < (int)nums.size()){
                if(currNumber != nums[nextDiffNumIndex]){
                    break;
                }
                
                nextDiffNumIndex++;
            }
            
            if(nextDiffNumIndex == (int)nums.size()){
                return k;
            }else{
                nums[k] = nums[nextDiffNumIndex];
                k++;
            }
            
            i = nextDiffNumIndex-1;
        }
            
        return k;
    }
};


// Solution 2

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        
        for(int i = 1;i < (int)nums.size();i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            
            nums[k] = nums[i];
            k++;
        }
        
        return k;
    }
};
