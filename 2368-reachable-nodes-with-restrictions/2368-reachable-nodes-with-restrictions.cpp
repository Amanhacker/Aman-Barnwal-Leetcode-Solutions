class Solution {
public:

    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &vis, vector<int> &blocked, int &ans) {
        
        vis[node] = 1;
        ans++;
        
        for(auto &ch : adj[node]) {
            
            if(blocked[ch] == 1) {
                vis[ch] = 1;
                continue;
            }   
            
            if(vis[ch] == 0) {
                dfs(ch, adj, vis, blocked, ans);
            }
        }
        
        return;
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    
        int ans = 0;
        
        unordered_map<int, vector<int>> adj;
        
        // Build the Undirected Graph
        
        for(auto &x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> vis(n, 0), blocked(n, 0);
        
        for(auto x : restricted) {
            blocked[x] = 1;
        }
        
        dfs(0, adj, vis, blocked, ans);
        
        return ans;
    }
    
};