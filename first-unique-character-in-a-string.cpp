// Problem: https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> letterCount(256, 0);
        
        for(int i = 0;i < s.length();i++){
            letterCount[s[i]]++;
        }
        
        for(int i = 0;i < s.length();i++){
            if(letterCount[s[i]] == 1){
                return i;
            }
        }
        
        return -1;
    }
};
