// Problem: https://leetcode.com/problems/swim-in-rising-water/

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
    int swimInWater(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<int> position(n*n, 0);
        
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                position[grid[i][j]] = i*n + j;
            }
        }
        
        UnionFind uf(n*n);
        
        for(int t = 0; t < n*n;t++){
            int currPosition = position[t];
            
            int i = currPosition/n;
            int j = currPosition%n;
            
            if(i-1 >= 0 && grid[i-1][j] <= grid[i][j]){
                uf.union_set((i-1)*n+j, currPosition);
            }
            if(i+1 < n && grid[i+1][j] <= grid[i][j]){
                uf.union_set((i+1)*n+j, currPosition);
            }
            if(j-1 >= 0 && grid[i][j-1] <= grid[i][j]){
                uf.union_set(i*n+(j-1), currPosition);
            }
            if(j+1 < n && grid[i][j+1] <= grid[i][j]){
                uf.union_set(i*n+(j+1), currPosition);
            }
            
            if(uf.find_set(0) == uf.find_set(n*n-1)){
                return t;
            }
        }
        
        return -1;
    }
};
