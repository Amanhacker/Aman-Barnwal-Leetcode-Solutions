class Solution {
public:
    
    void dfs(int node, int nodeAnc, vector<int> &vis, unordered_map<int, vector<int>> &adj, vector<vector<int>> &res) {
        
        vis[node] = 1;
        
        for(auto &x : adj[node]) {
            
            if(vis[x] == 0) {
                res[x].push_back(nodeAnc);
                dfs(x, nodeAnc, vis, adj, res);
            }
        }
        
        return;
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    
        vector<vector<int>> res(n);
        unordered_map<int, vector<int>> adj;
        
        for(auto &x : edges) {
            adj[x[0]].push_back(x[1]);
        }
        
        for(int i=0; i<n; i++) {
            vector<int> vis(n);
            dfs(i, i, vis, adj, res);
        }
        
        return res;
    }
    
};