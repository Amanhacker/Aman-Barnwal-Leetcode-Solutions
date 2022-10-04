class Solution {
public:
    
    // Return true if cycle
    bool dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &vis) {
        
        if(vis[node] == 2)                          return true;
        
        vis[node] = 2;
        
        for(int i=0; i<adj[node].size(); i++) {
            int child = adj[node][i];
            if(vis[child] != 1) {
                if(dfs(child, adj, vis) == true)    return true;
            }                    
        }
        
        vis[node] = 1;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& prereq) {
    
        // Topological Sort
    
        unordered_map<int, vector<int>> adj;
        
        for(auto &x : prereq) {
            
            int u = x[0];
            int v = x[1];
            
            // v -> u
            adj[v].push_back(u);
        }
        
        vector<int> vis(n, 0);
        
        // 0 - unvisited, 1 - processing, 2 - processed
        
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                // if cycle then not possible
                if(dfs(i, adj, vis) == true)            return false;
            }
        }
        
        return true;
    }
    
};