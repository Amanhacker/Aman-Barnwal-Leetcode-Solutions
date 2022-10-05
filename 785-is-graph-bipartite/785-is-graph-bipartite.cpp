class Solution {
public:
    
    bool dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &vis, vector<int> &col, int c) {
        
        vis[node] = 1;
        col[node] = c;
        
        for(auto &ch : adj[node]) {
            if(vis[ch] == 0) {
                if(dfs(ch, adj, vis, col, c ^ 1) == false)               return false;
            }
            else {
                if(col[node] == col[ch])                                return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
    
        // Create a graph using Adjacency List
        unordered_map<int, vector<int>> adj;
        int n = graph.size();
        
        for(int i=0; i<graph.size(); i++) {
            
            // All nodes of graph[i] are adjacent to node i
            
            for(auto &x : graph[i])                 adj[i].push_back(x);
        }
        
        vector<int> vis(n, 0), col(n, 0);
        
        for(int i=0; i<n; i++) {
            
            if(vis[i] == 0) {
                if(dfs(i, adj, vis, col, 0) == false)               return false;
            }
        }
        
        return true;
    }
    
};