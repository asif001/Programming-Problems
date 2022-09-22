// Problem: https://leetcode.com/problems/redundant-connection/

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
    
    bool union_set(int a, int b){
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
            
            return true;
        }else{
            return false;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = (int)edges.size() + 1;
        
        UnionFind uf(n);
        
        for(int i = 0;i < edges.size();i++){
            if(!uf.union_set(edges[i][0], edges[i][1])){
                return edges[i];
            }
        }
        
        return vector<int>();
    }
};
