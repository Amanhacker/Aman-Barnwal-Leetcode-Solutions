class Solution {
public:

    void dfs(int node, map<int, vector<int>> &adj, vector<vector<int>> &res, vector<int> path,  int n) {
        
        path.push_back(node);
        
        if(node == n-1) {
            res.push_back(path);
            return;
        }
        
        for(int i=0; i<adj[node].size(); i++) {
            int child = adj[node][i];
            dfs(child, adj, res, path, n);
        }
        
        path.pop_back();
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    
        vector<vector<int>> res;
        int n = graph.size();
        
        map<int, vector<int>> adj;
        
        int i = 0;
        
        for(auto x : graph) {
            for(auto &x1 : x) {
                
                // node i to node x1 i.e i -> x1
                adj[i].push_back(x1);
            }

            i++;
        }
        
        vector<int> path;
        dfs(0, adj, res, path, n);
        
        return res;
    }
    
};