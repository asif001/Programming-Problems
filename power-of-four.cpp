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

// Solution by bit manipulation

class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && ((n & (n - 1)) == 0) && ((n - 1) % 3 == 0);
    }
};
