// Problem: https://leetcode.com/problems/counting-bits/description/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        
        for(int i = 0;i < n+1;i++){
            int temp = i, cnt = 0;
            while(temp > 0){
                if(temp & 1){
                    cnt++;
                }
                
                temp = temp >> 1;
            }
            
            res[i] = cnt;
        }
        
        return res;
    }
};
