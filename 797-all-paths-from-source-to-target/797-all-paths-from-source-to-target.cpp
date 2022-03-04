class Solution {
public:

    void dfs(int node, vector<vector<int>> &adj, vector<vector<int>> &res, vector<int> path,  int n) {
        
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
        
        vector<int> path;
        dfs(0, graph, res, path, n);
        
        return res;
    }
    
};