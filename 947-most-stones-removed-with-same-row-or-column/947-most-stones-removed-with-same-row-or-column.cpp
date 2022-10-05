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
    
    int removeStones(vector<vector<int>>& stones) {
    
        int n = stones.size();
        
        unordered_map<int, vector<int>> adj;
        
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n, 0);
        int cc = 0;
        
        // Let's consider a stone to be node
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                dfs(i, adj, vis);
                cc++;
            }
        }
        
        return n - cc;
    }
    
};