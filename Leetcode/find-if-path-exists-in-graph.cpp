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

