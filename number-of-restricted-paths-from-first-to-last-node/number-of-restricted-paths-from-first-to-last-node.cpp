class Solution {
public:
    
    // Using Dijkstra Algorithm + DFS with Memoization
    
    int dfs(int node, vector<int> &dp, vector<int> &dist, unordered_map<int, vector<pair<int, int>>> &adj) {
        
        int mod = 1e9 + 7;

        // If reach the source vertex
        if(node == 1)                                                            return 1;

        // If value already present at dp
        if(dp[node] != -1)                                                       return dp[node];

        int sum = 0;
        int wt = dist[node];

        for(int i=0; i<adj[node].size(); i++) {

            int prev_node = adj[node][i].second;
            int val = dist[prev_node];
            
            // if min dist to prev node is greater than min dist to cur node, then run dfs to prev node till you reach 1
            if(val > wt) {
                
               // sum += dfs(prev_node, dp, dist, adj) % mod 
               sum = (sum % mod + dfs(prev_node, dp, dist, adj) % mod) % mod;
           }
        }

        dp[node] = sum % mod;
        return dp[node];
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
    
        int ans = 0;
        
        // Calculate the min distance of each node from node n using Dijkstra Algorithm
        
        // Form the graph
        
        unordered_map<int, vector<pair<int, int>>> adj;         // 1st arg - node1, 2nd arg - dist, 3rd arg - node2
        
        for(int i=0; i<edges.size(); i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            int wt = edges[i][2];
            
            // Undirected edge between node u and node v having weight wt
            adj[u].push_back({wt, v});
            adj[v].push_back({wt, u});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, n});
        dist[n] = 0;
        
        while(pq.empty() == false) {
            
            pair<int, int> cur = pq.top();
            pq.pop();
            
            int cur_node = cur.second;
            int cur_wt = cur.first;
            
            for(int i=0; i<adj[cur_node].size(); i++) {
                
                pair<int, int> w = adj[cur_node][i];
                
                int w_node = w.second;
                int w_wt = w.first;
                
                if(dist[w_node] > cur_wt + w_wt) {
                    dist[w_node] = cur_wt + w_wt;
                    pq.push({dist[w_node], w_node});
                }
            }
        }
        
        // for(int i=1; i<=n; i++)                                 cout << dist[i] << " ";
        // cout << endl;
        
        vector<int> dp(n + 1, -1);
        return dfs(n, dp, dist, adj);
    }
    
};