//Problem: https://leetcode.com/problems/power-of-four/description/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0){
            return false;
        }
        
        double tempx = log2((double)n)/2;
        double tempn = pow(4, (int)tempx);
        
        if(n == (int)tempn){
            return true;
        }else{
            return false;
        }
    }
};

// Solution without overflow

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = (int)nums.size();
        
        for(int i = 0;i < (int)nums.size();i++){
            res = res ^ i;
            res = res ^ nums[i];
        }
        
        return res;
    }
};
