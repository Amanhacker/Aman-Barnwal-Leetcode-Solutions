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
        vector<long long> ccCountNodes;
        
        // No of total pairs
        count = ( (long long)n * (n-1) )/2;
        
        for(int i=0; i<n; i++) {
            
            if(vis[i] == 0) {
                
                long long nodesCount = 0;
                dfs(i, adj, vis, nodesCount);
                
                count -= (nodesCount * (nodesCount - 1) ) / 2;
                
                
                // for(auto &x : ccCountNodes) {
                //     count += x * nodesCount; 
                // }
                
                // ccCountNodes.push_back(nodesCount);   
            }
        }
        
//         int n1 = ccCountNodes.size();
        
//         for(int i=0; i<n1-1; i++) {
//             for(int j=i+1; j<n1; j++) {
//                 count += ccCountNodes[i] * ccCountNodes[j];
//             }
//         }
        
        return count;
    }
    
};