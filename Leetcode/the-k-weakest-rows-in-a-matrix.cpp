// Problem: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution {
public:
    struct compare
    {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
        {
            if(a.first == b.first){
                return a.second < b.second;
            }else{
                return a < b;
            }
        }
    };
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int numOfRows = mat.size();
        int numOfColumns = mat[0].size();
        vector<pair<int, int>> strength(numOfRows);
        vector<int> result(k);
        
        for(int i = 0;i < numOfRows;i++){
            strength[i].second = i;
            
            int low = 0;
            int high = numOfColumns - 1;
            
            while(low <= high){
                int mid = (high - low)/2 + low;
                
                if(mat[i][mid] == 1){
                    low++;
                }else{
                    high--;
                }
            }
            
            strength[i].first = low;
        }
        
        sort(strength.begin(), strength.end(), compare());
        
        for(int i = 0; i < k;i++){
            result[i] = strength[i].second;
        }
        
        return result;
    }
};
