class Solution {
public:
    
    // Using DFS
    
    void dfs(int node, vector<int> adj[], vector<int> &vis, int &res) {
        
        vis[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++) {
           
            int child = adj[node][i];
            
            if(vis[abs(child)] == 0) {
                
                if(child > 0)                                           res++;
                dfs(abs(child), adj, vis, res);
            }
        }
        
        return;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
    
        int res = 0;
        vector<int> adj[n];
        
        // An undirected graph adj, where we are giving (+ve) sign to outgoing edges,
        // Also, pretend that there is also same incoming edge & insert it into adj[] list as (-ve) elements.
        
        // This is done so that the DFS doesn't stop when there are no outgoing edges 
        // (+ve edges) from the current edge. (Because there might be more outgoing edges afterwards)
        
        for(int i=0; i<connections.size(); i++) {
            
            int u = connections[i][0];
            int v = connections[i][1];
            
            // Road from city u to city v
            adj[u].push_back(v);
            adj[v].push_back(-u);
        }
        
        vector<int> vis(n, 0);
        
        // Start dfs from node 0
        dfs(0, adj, vis, res);
        
        
        return res;
    }
    
};