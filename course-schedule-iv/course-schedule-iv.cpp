class Solution {
public:
    
    // Using DFS
    
    bool dfs(int node, int dest, unordered_map<int, vector<int>> &adj, vector<int> &vis) {

        // if dfs(node) leads to dest, then return true
        if(node == dest)                                        return true;
        if(vis[node] == 1)                                      return false;
    
        vis[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++) {

            int child = adj[node][i];
            
            if(vis[child] == 0) {
                if(dfs(child, dest, adj, vis) == true)         return true;
            }
        }

        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prereq, vector<vector<int>>& queries) {

        vector<bool> res;

        // Use Topological sort in layerwise fashion

        int n = numCourses;

        unordered_map<int, vector<int>> adj;

        for(int i=0; i<prereq.size(); i++) {

            int u = prereq[i][0];
            int v = prereq[i][1];

            // Course u needs to be completed before course v i.e u -> v
            adj[u].push_back(v);
        }

        // If, there are no prerequisites, then each course is independent
        if(prereq.size() == 0) {
            res.resize(n, false);
            return res;
        }

        vector<int> vis(n, 0);

        for(int i=0; i<queries.size(); i++) {

            int u = queries[i][0];
            int v = queries[i][1];
            
            // Make all the nodes unvisited
            fill(vis.begin(), vis.end(), 0);
            
            res.push_back(dfs(u, v, adj, vis));
        }

        return res;
    }

    
};