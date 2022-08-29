// Problem: https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int charCount[256] = {0};
        
        for(int i = 0;i < magazine.length();i++){
            charCount[magazine[i]]++;
        }
        
        for(int i = 0; i < ransomNote.length();i++){
            if(charCount[ransomNote[i]] > 0){
                charCount[ransomNote[i]]--;
            }else{
                return false;
            }
        }
        
        return true;
    }
};
