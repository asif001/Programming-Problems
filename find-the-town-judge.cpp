// Problem: https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> numOfInDegree(n+1, 0);
        vector<int> numOfOutDegree(n+1, 0);
        
        for(int i = 0;i < (int)trust.size();i++){
            numOfOutDegree[trust[i][0]]++;
            numOfInDegree[trust[i][1]]++;
        }
        
        for(int i = 1;i <= n;i++){
            if(numOfOutDegree[i] == 0 && numOfInDegree[i] == n-1){
                return i;
            }
        }
        
        return -1;
    }
};
