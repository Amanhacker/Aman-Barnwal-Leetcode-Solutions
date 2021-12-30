class Solution {
public:
    
    
    void dfs(int node, vector<int> &vis, unordered_map<int, vector<int>> &adj) {
        
        vis[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++) {
            
            int child = adj[node][i];
            
            if(vis[child] == 0)                                                 dfs(child, vis, adj);
        }
        
        return;
    }
   
    int removeStones(vector<vector<int>>& stones) {
    
        int res;
        
        // Form a undirected graph using co-ordinates of stones
        
        unordered_map<int, vector<int>> adj;
        int n = stones.size();
        
        // Let's say, the nodes are from [0, n-1]
        
        for(int i=0; i<stones.size()-1; i++) {
            for(int j=i+1; j<stones.size(); j++) {
                
                // if either row or column no is same of both stones then they will be connected
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);                            // Let's consider a stone to be a node
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n, 0);
        
        int cc = 0;                                 // No.of connected components
        
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                dfs(i, vis, adj);
                cc++;
            }
        }
        
        res = stones.size() - cc;
        return res;
    }
    
};