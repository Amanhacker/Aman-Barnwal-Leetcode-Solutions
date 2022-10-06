class Solution {
public:
    
    bool dfs(int node, int dest, unordered_map<int, vector<int>> &adj, vector<int> &vis) {
        
        if(node == dest)                                    return true;
        if(vis[node] == 1)                                  return false;
        
        vis[node] = 1;
        
        for(auto &ch : adj[node]) {
            if(vis[ch] == 0) {
                if(dfs(ch, dest, adj, vis) == true)         return true;
            }
        }
        
        return false;
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& q) {
    
        vector<bool> res;
        unordered_map<int, vector<int>> adj;
        
        for(auto &x : prereq) {
            adj[x[0]].push_back(x[1]);
        }
        
        if(prereq.size() == 0) {
            res.resize(n, false);
            return res;
        }
        
        vector<int> vis(n, 0);
        
        for(int i=0; i<q.size(); i++) {
            
            int u = q[i][0];
            int v = q[i][1];
            
            // Make all nodes unvisited
            fill(vis.begin(), vis.end(), 0);
            res.push_back(dfs(u, v, adj, vis));
        }
        
        return res;
    }
    
};