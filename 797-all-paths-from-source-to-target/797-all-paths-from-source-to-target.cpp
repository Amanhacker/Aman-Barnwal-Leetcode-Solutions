class Solution {
public:

    void dfs(int node, int dest, vector<int> &vis, vector<int> temp, vector<vector<int>> &res, unordered_map<int, vector<int>> &adj) {
        
        temp.push_back(node);
        
        if(node == dest) {
            res.push_back(temp);
        }
        
        vis[node] = 1;
        
        for(auto &ch : adj[node]) {
            if(vis[ch] == 0) {
                dfs(ch, dest, vis, temp, res, adj);
            }
        }
        
        temp.pop_back();
        vis[node] = 0;
        
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    
        vector<vector<int>> res;
        unordered_map<int, vector<int>> adj;
        
        int n = graph.size();
        
        for(int i=0; i<graph.size(); i++) {
            
            vector<int> t = graph[i];
            for(auto &x : t)                        adj[i].push_back(x);
            
        }
        
        // From node 0 to node (n - 1)
        
        vector<int> temp, vis(n, 0);
        
        dfs(0, n-1, vis, temp, res, adj);
        return res;
    }
    
};