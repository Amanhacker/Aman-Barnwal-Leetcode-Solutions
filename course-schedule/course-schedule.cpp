class Solution {
public:
    
    // It returns true if it contains a cycle, else returns false
    
    // 0 means unvisited, 1 - processed, 2 - processing
    bool dfs(int node, vector<int> &vis, unordered_map<int, vector<int>> &adj) {
                
        // if it dfs reaches to processing nodes
        if(vis[node] == 2)                                                    return true;
        
        vis[node] = 2;
        
        for(int i=0; i<adj[node].size(); i++) {
            
            int child = adj[node][i];
            
            // if dfs reaches to not already processed nodes
            if(vis[child] != 1) {
                if(dfs(child, vis, adj) == true)                         return true;
            }
        }
        
        // Make the node processed
        
        vis[node] = 1;
        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
    
        // Form the graph
        
        unordered_map<int, vector<int>> adj;
        int n = numCourses;
        
        for(int i=0; i<prereq.size(); i++) {
            
            int u = prereq[i][0];
            int v = prereq[i][1];
            
            // Course v needs to be completed before course u i.e v -> u
            adj[v].push_back(u);
        }
        
        vector<int> vis(numCourses, 0);
        
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                // if it contains a cycle, then it's not possible to complete all courses
                if(dfs(i, vis, adj) == true)                                                   return false;
            }
        }        
        
        return true;
    }
    
};