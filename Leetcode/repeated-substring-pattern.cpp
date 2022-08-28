// Problem: https://leetcode.com/problems/repeated-substring-pattern/

// Solution with O(nsqrt(n)) time complexity
// We need to find all divisors of string's length. let's say divisor is k. As n%k = 0, we can build the string by appending the substring of length k, (n/k) times

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int lengthOfString = s.length();
        for(int  i = 1;i*i<=lengthOfString && lengthOfString >= 2;i++){
            if(lengthOfString%i == 0){
                string firstPattern = "", secondPattern = "", resultPattern = "";
                int lengthOfFirstPattern = i;
                int lengthOfSecondPattern = lengthOfString/i;
                
                firstPattern = s.substr(0, lengthOfFirstPattern);
                secondPattern = s.substr(0,lengthOfSecondPattern);
                
                while(resultPattern.length() < lengthOfString && lengthOfFirstPattern != lengthOfString){
                    resultPattern.append(firstPattern);
                }
                
                if(resultPattern == s){
                    return true;
                }
                
                resultPattern = "";
                
                while(resultPattern.length() < lengthOfString && lengthOfSecondPattern != lengthOfString){
                    resultPattern.append(secondPattern);
                }
                
                if(resultPattern == s){
                    return true;
                }
            }
        }
        
        return false;
    }
};


// Solution with O(n) time complexity
// We need to create an LPS array from KMP algorithm. If there are repeated string then the last index of array will return how many times the characters are repeated
// Let's say string is "abcabc". LPS = [0,0,0,1,2,3]
// Then length of repeated pattern is LPS[last index] - length of string = 3
// check (length of string % (LPS[laste index] - length of string)) == 0

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i = 1, j = 0, n = s.length();
        vector<int> lps(n, 0);
        
        while(i < n){
            if(s[i] == s[j]){
                lps[i] = j + 1;
                i = i + 1;
                j = j + 1;
            }else if(j != 0){
                j = lps[j-1];
            }else{
                lps[i] = 0;
                i = i + 1;
            }
        }
        
        if(lps[n-1] != 0 && n % (n - lps[n-1]) == 0){
            return true;
        }
        
        return false;
    }
};

// Another solution
// But the second solution is the best. as it is always O(n). Below solution depends totally on the STL implementation. Which does not guaratee O(n)
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        return (str + str).substr(1, str.size() * 2 - 2).find(str)!=-1;
    }
};
