class Solution {
public:
    
    unordered_map<int, vector<int>> adj;
    vector<int> vis;
    
    int maxD, maxNode;
    
    void dfs(int node, int d) {
        
        vis[node] = 1;
        
        if(maxD < d) {
            maxD = d;
            maxNode = node;
        }
        
        for(int i=0; i<adj[node].size(); i++) {
            
            int child = adj[node][i];
            
            if(vis[child] == 0) {
                dfs(child, d + 1);
            }
        }
        
        return;
    }
    
    int treeDiameter(vector<vector<int>>& edges) {
    
        // Find the longest path in this graph
        
        int e = edges.size();               // No.of edges
        int n = e + 1;                      // No. of nodes from [0, n-1]
        
        vis.resize(n, 0);
        
        // Form the graph
        for(int i=0; i<edges.size(); i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        maxD = -1;
        
        // Run two dfs, first dfs at source 0 and second dfs at source maxNode
        dfs(0, 0);
        
        maxD = -1;
        for(int i=0; i<n; i++)               vis[i] = 0;
        
        dfs(maxNode, 0);
        
        return maxD;
    }
    
};