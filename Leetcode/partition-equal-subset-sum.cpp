// Problem: https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool partitionSubset(vector<int>& nums, vector<vector<char>>& mem, int index, int sum){
        if(sum == 0){
            mem[index][sum] = '1';
            return true;
        }
        
        if(index == 0){
            if(sum == nums[index]){
                mem[index][sum] = '1';
            }else{
                mem[index][sum] = '2';
            }
            
            return sum == nums[index];
        }
        
        if(mem[index][sum] != '0'){
            if(mem[index][sum] == '1'){
                return true;
            }else{
                return false;
            }
        }
        
        if(sum >= nums[index]){
            bool way1 = partitionSubset(nums, mem, index-1, sum-nums[index]);
            if(way1){
                mem[index][sum] == '1';
                return true;
            }
        }
        
        bool way2 = partitionSubset(nums, mem, index-1, sum);
        if(way2){
            mem[index][sum] = '1';
            return true;
        }
        
        mem[index][sum] = '2';
        return false;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0){
            return false;
        }
        
        vector<vector<char>> mem(n, vector<char>((sum>>1)+1, '0'));
        
        return partitionSubset(nums, mem, n-1, sum>>1);
    }
};
