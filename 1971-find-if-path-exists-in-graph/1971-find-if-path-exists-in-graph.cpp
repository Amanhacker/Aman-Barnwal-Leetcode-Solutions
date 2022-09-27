class Solution {
public:

    void dfs(int node, int dest, unordered_map<int, vector<int>> &adj, bool &flag, vector<int> &vis) {
        
        if(flag == true)                            return;
        
        if(node == dest) {
            flag = true;
            return;
        }
        
        vis[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++) {
            
            int child = adj[node][i];
            
            if(vis[child] == 0) {
                dfs(child, dest, adj, flag, vis);
            }
        }
        
        return;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
    
        // Nodes from 0 to (n-1)
        
        // Check if there exists a valid path between src and dest
        
        // Using Adjacency List
        
        unordered_map<int, vector<int>> adj;
        
        for(auto &x : edges) {
            
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> vis(n, 0);
            
        bool flag = false;
        dfs(src, dest, adj, flag, vis);
        
        return flag;
    }
    
};