//Problem: https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        
        for(int i = 0; i < (int)s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                brackets.push(s[i]);
            }else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(brackets.empty()){
                    return false;
                }
                
                char curr = brackets.top();
                if(curr != s[i] - 1 && curr != s[i] - 2){
                    return false;
                }
                
                brackets.pop();
            }
        }
        
        if(!brackets.empty()){
            return false;
        }
        
        return true;
    }
};
