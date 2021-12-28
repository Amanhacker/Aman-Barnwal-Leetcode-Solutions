class Solution {
public:
    
    void dfs(int src, int dest, vector<int> path, vector<vector<int>> &res, vector<vector<int>> graph) {
        
        path.push_back(src);
        
        // Base Condition
        if(src == dest)                                              res.push_back(path);
        
        else {
            
            for(int i=0; i<graph[src].size(); i++) {
                int child = graph[src][i];
                dfs(child, dest, path, res, graph);
            }
        }
        
        path.pop_back();
        
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    
        vector<vector<int>> res;
        vector<int> path;
        
        if(graph.size() == 0)                                          return res;
        
        int n = graph.size();
        
        dfs(0, n-1, path, res, graph);
        
        return res;
    }
    
};