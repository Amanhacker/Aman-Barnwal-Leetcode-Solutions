class Solution {
public:
    
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &vis, long long &nodeCount) {
        
        vis[node] = 1;
        nodeCount++;
        
        for(auto &ch : adj[node]) {
            if(vis[ch] == 0) {
                vis[ch] = 1;
                dfs(ch, adj, vis, nodeCount);
            }
        }

        return;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
    
        long long count = 0;
        unordered_map<int, vector<int>> adj;
        
        for(auto &x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }        
        
        vector<int> vis(n, 0);
        
        // No of total pairs
        count = ( (long long)n * (n-1) )/2;
        
        for(int i=0; i<n; i++) {
            
            if(vis[i] == 0) {
                
                long long nodesCount = 0;
                dfs(i, adj, vis, nodesCount);
                
                // No of pairs formed by this connected components which are reachable from each other, so we need to subtract this
                count -= (nodesCount * (nodesCount - 1) ) / 2;
            }
        }
        
        return count;
    }
    
};