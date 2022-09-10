// Problem: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0)
            return 0;
        
        int step = 1;
        while(num != 1){
            step = step + (num&1)+ 1;
            num = num >> 1;
        }
        
        return step;
    }
};
