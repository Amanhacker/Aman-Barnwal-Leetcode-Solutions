class Solution {
public:

    // DFS using DP + Memoization
	
    int dfs(unordered_map<int, vector<pair<int, int>>> &adj, int src, int dest, int k, vector<vector<int>> &dp) {
        
        if (src == dest)                                return 0;
        if (k <= -1)                                    return INT_MAX;
        
        if (dp[src][k] != -1)                           return dp[src][k];
        
        int ans = INT_MAX;
        
        for(int i=0; i<adj[src].size(); i++) {
        
            pair<int, int> ch = adj[src][i];
            
            int child_node = ch.second;
            
            int res = dfs(adj, child_node, dest, k-1, dp);
            
            if (res != INT_MAX)                         ans = min(ans, ch.first + res);
        }
        
        dp[src][k] = ans;
        return ans;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        
        // Build the graph
        unordered_map<int, vector<pair<int, int>>> adj;
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        
        for (int i=0; i<flights.size(); i++) {
            
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            
            // Edge from node u to node v with weight wt
            adj[u].push_back({wt, v});
        }
        
        // Make DFS Call
        int ans = dfs(adj, src, dest, k, dp);  
        
        if (ans == INT_MAX)                                             return -1;
        
        return ans;
    }
    
};