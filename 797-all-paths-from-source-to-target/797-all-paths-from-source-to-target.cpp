class Solution {
public:
    
    void dfs(int src, int dest, vector<vector<int>> &adj, vector<int> path, vector<vector<int>> &res) {
        
        path.push_back(src);
        
        // Base Condition
        if(src == dest) {
            res.push_back(path);
            return;
        }
        
        for(int i=0; i<adj[src].size(); i++) {
            int child = adj[src][i];
            dfs(child, dest, adj, path, res);
        }
        
        path.pop_back();
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    
        vector<vector<int>> res;
        vector<int> path;
        
        int n = graph.size();
        
        dfs(0, n - 1, graph, path, res);
        
        return res;
    }
    
};