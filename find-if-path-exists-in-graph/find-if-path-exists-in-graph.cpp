class Solution {
public:
    
    void dfs(int node, int end, unordered_map<int, vector<int>> &adj, vector<int> &vis, bool &flag) {
        
        if(flag == true)                                                return;
        
        if(node == end) {
            flag = true;
            return;
        }
        
        vis[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++) {
            
            int child = adj[node][i];
            
            if(vis[child] == 0) {
                dfs(child, end, adj, vis, flag);
            }
        }
        
        return;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
    
        unordered_map<int, vector<int>> adj;
        
        // Make the graph
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> vis(n, 0);
        bool flag = false;
        
        dfs(start, end, adj, vis, flag);
        
        return flag;
    }
    
};