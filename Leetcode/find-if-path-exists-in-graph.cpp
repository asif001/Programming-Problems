// Problem: https://leetcode.com/problems/find-if-path-exists-in-graph/

// DFS

class Solution {
public:
    bool dfs(vector<vector<int>>& adjList, vector<bool>& visited, int source, int destination){
        visited[source] = true;
        
        if(source == destination){
            return true;
        }
        
        for(int v : adjList[source]){
            if(visited[v] == false && dfs(adjList, visited, v, destination)){
                return true;
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);
        
        for(vector<int> edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        return dfs(adjList, visited, source, destination);
    }
};

// BFS

class Solution {
public:    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);
        
        for(vector<int> edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            if(u == destination){
                return true;
            }
            
            for(int v : adjList[u]){
                if(visited[v] == false){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        
        return false;
    }
};

// Union find

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
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        UnionFind uf(n);
        
        for(vector<int> edge : edges){
            uf.union_set(edge[0], edge[1]);
        }
        
        return uf.find_set(start) == uf.find_set(end);
    }
};
