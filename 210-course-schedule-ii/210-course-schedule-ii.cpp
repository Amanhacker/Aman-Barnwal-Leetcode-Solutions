class Solution {
public:
    
    void bfs(int n, unordered_map<int, vector<int>> &adj, vector<int> &indegree, vector<int> &res) {
        
        queue<int> q;
        
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0)            q.push(i);
        }
        
        while(q.empty() == false) {
            
            int n = q.size();
            
            while(n--) {
                
                int temp = q.front();
                q.pop();
                
                res.push_back(temp);
                
                for(int j=0; j<adj[temp].size(); j++) {
                    
                    int child = adj[temp][j];
                    indegree[child]--;
                    
                    if(indegree[child] == 0) {
                        q.push(child);
                    }
                }
            }
        }
        
        return;
    }
    
    // Returns true if contains a cycle
    bool dfs(vector<int> &vis, unordered_map<int, vector<int>> &adj, int node) {
        
        // 0 - unvisited, 1 - processing, 2 - processed
        
        if(vis[node] == 2)                              return true;
        
        vis[node] = 2;
        
        for(int i=0; i<adj[node].size(); i++) {
            
            int child = adj[node][i];
            
            if(vis[child] != 1) {
                if(dfs(vis, adj, child) == true)        return true;
            }
        }
        
        vis[node] = 1;
        return false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
    
        vector<int> res;
        
        // Using Topological sorting
        
        vector<int> indegree(n, 0), vis(n, 0);
        unordered_map<int, vector<int>> adj;
        
        for(auto &x : prereq) {
            
            int u = x[0];
            int v = x[1];
            
            // v -> u
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        bool flag = false;      // if cycle is not present
        
        for(int i=0; i<n; i++) {
            
            if(flag == true)    break;
            
            if(vis[i] == 0) {
                if(dfs(vis, adj, i) == true) {
                    flag = true;
                    break;
                }
            }
        }
        
        if(flag == false)       bfs(n, adj, indegree, res);
        
        return res;
    }
};