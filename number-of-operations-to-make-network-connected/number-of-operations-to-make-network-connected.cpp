class Solution {
public:
    
    void dfs(int node, vector<int> &vis, unordered_map<int, vector<int>> &adj) {
        
        vis[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++) {
          
            int child = adj[node][i];
            if(vis[child] == 0)                                     dfs(child, vis, adj);
        }
        
        return;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
    
        // Calculate no.of connected components(cc) and no.of extra or back edges without which the nodes of the CC are connected (extraEdges)
        int cc = 0;
        
        int e = connections.size();
        
        // For a Acyclic graph, no.of edges should be n - 1
        
        // if no.of edges present is less than (n - 1), then its impossible to make a single connected graph
        if(e < n - 1)                                       return -1;
        
        
        // Form the graph
        unordered_map<int, vector<int>> adj;
        
        for(auto x : connections) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> vis(n, 0);
        
        // Find no.of connected components
        for(int i=0; i<n; i++) {
        
            if(vis[i] == 0) {
                dfs(i, vis, adj);
                cc++;    
            }
        }
        
        return cc - 1;
    }
    
};