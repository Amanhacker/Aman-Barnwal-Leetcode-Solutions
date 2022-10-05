class Solution {
public:
    
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &vis) {
        
        vis[node] = 1;
        
        for(auto &ch : adj[node]) {
            if(vis[ch] == 0) {
                dfs(ch, adj, vis);
            }
        }
        
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
    
        int count = 0;
        
        int n = isConnected.size();
        int m = isConnected[0].size();
        
        unordered_map<int, vector<int>> adj;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        } 
        
        vector<int> vis(n, 0);
        
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                dfs(i, adj, vis);
                count++;
            }
        }
        
        return count;
    }
    
};