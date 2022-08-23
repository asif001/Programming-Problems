//Problem: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numberToidx;
        vector<int> res(2, -1);
        
        for(int i = 0;i < (int)nums.size();i++){
            int numToFind = target - nums[i];
            
            auto it = numberToidx.find(numToFind);
            
            if(it == numberToidx.end()){
                numberToidx[nums[i]] = i;
            }else{
                res[0] = i;
                res[1] = numberToidx[numToFind];
                break;
            }
        }
        
        return res;
    }
};
