// Problem: https://leetcode.com/problems/island-perimeter/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimiter = 0;
        
        for(int r = 0;r < grid.size();r++){
            for(int c = 0; c < grid[r].size();c++){
                if(grid[r][c] == 1){
                    perimiter += 4;
                    
                    if(c-1>=0 && grid[r][c-1] == 1){
                        perimiter -= 1;
                    }
                    if(c+1< grid[r].size() && grid[r][c+1] == 1){
                        perimiter -= 1;
                    }
                    if(r-1>=0 && grid[r-1][c] == 1){
                        perimiter -= 1;
                    }
                    if(r+1<grid.size() && grid[r+1][c] == 1){
                        perimiter -= 1;
                    }
                }
            }
        }
        
        return perimiter;
    }
};
