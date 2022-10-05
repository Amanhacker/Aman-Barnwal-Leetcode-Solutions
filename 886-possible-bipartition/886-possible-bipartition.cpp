class Solution {
public:

    bool dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &vis, vector<int> &col, int c) {
        
        vis[node] = 1;
        col[node] = c;
        
        for(auto &ch : adj[node]) {
            
            if(vis[ch] == 0) {
                if(dfs(ch, adj, vis, col, c ^ 1) == false)          return false;
            }
            else {
                if(col[ch] == col[node])                            return false;
            }
        }
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    
        unordered_map<int, vector<int>> adj;
        
        for(auto &x : dislikes) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> col(n + 1, 0), vis(n + 1, 0);
        
        // If graph is bipartite, then we are able to split the graph in 2 groups
        
        for(int i=1; i<=n; i++) {
            if(vis[i] == 0) {
                if(dfs(i, adj, vis, col, 0) == false)               return false;
            }
        }
        
        return true;
    }
    
};