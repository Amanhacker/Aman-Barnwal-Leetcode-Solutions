class Solution {
public:
    
    // Returns true if cycle exists, else false
    void dfs(int node, int dest, unordered_map<int, vector<int>> &adj, vector<int> &vis, bool &flag) {
        
        if(flag == true)                    return;
        
        if(node == dest) {
            flag = true;
            return;
        }   
        
        vis[node] = 1;
        
        for(auto &ch : adj[node]) {
            
            if(vis[ch] == 0) {
                dfs(ch, dest, adj, vis, flag);
            }
        } 
        
        return;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    
        vector<int> res;
        
        unordered_map<int, vector<int>> adj;
        int n = edges.size();
        
        for(auto &x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> vis(n + 1, 0);
        
        for(int i=edges.size()-1; i>=0; i--) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            // if edge between u and v is removed, then check whether the cycle removed ?
            auto it1 = find(adj[u].begin(), adj[u].end(), v);
            auto it2 = find(adj[v].begin(), adj[v].end(), u);
            
            // Remove the edge
            if(it1 != adj[u].end())                       adj[u].erase(it1);
            if(it2 != adj[v].end())                       adj[v].erase(it2);
            
            
            for(int i=1; i<=n; i++)                       vis[i] = 0;

            // Check whether we can connect u and v without edges (u, v)
            bool flag = false;
            dfs(u, v, adj, vis, flag);
            
            if(flag == true) {
                
                res.push_back(u);
                res.push_back(v);
                
                return res;
            }
            
            // Add the edge again
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return res;
    }
    
};