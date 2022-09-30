// Problem: https://leetcode.com/problems/number-of-islands/

// UnionFind - O(n*n)
class UnionFind{
private:
    int* parent;
    int* rank;
    int n;
public:    
    UnionFind(int n){
        this->n = n;
        parent = new int[n];
        rank = new int[n];
        init();
    }
    
    void init(){
        for(int v = 0;v < n;v++){
            make_set(v);
        }
    }
    
    void make_set(int v){
        parent[v] = v;
        rank[v] = 0;
    }
    
    int find_set(int v){
        if(v == parent[v]){
            return v;
        }
        
        return parent[v] = find_set(parent[v]);
    }
    
    void union_set(int a, int b){
        int u = find_set(a);
        int v = find_set(b);
        
        if(u != v){
            if(rank[u] < rank[v]){
                swap(u,v);
            }
            
            parent[v] = u;
            if(rank[u] == rank[v]){
                rank[u]++;
            }
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        
        UnionFind uf(m*n);
        
        for(int k = 0; k < m*n;k++){            
            int i = k/n;
            int j = k%n;
            
            if(grid[i][j] == '1'){
                if(i+1 < m && grid[i+1][j] == '1'){
                    uf.union_set((i+1)*n+j, k);
                }
                if(j+1 < n && grid[i][j+1] == '1'){
                    uf.union_set(i*n+(j+1), k);
                }
            }
        }
        
        int numOfIslands = 0;
        
        for(int k = 0; k < m*n;k++){
            if(grid[k/n][k%n] == '1' && uf.find_set(k) == k){
                numOfIslands++;
            }
        }
        
        return numOfIslands;
    }
};
