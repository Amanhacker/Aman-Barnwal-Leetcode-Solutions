class Solution {
public:
    
    void dijkstra(int node, unordered_map<int, vector<pair<int, int>>> &adj, vector<int> &dist) {
        
        // Use Min Heap - 1st arg : weight, 2nd arg : node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, node});
        dist[node] = 0;
        
        while(pq.empty() == false) {
            
            int n = pq.size();
            
            while(n--) {
                
                pair<int, int> cur = pq.top();
                pq.pop();
                
                int curNode = cur.second;
                int curD = cur.first;
                
                for(auto &ch : adj[curNode]) {
                    
                    int wNode = ch.first;
                    int wDist = ch.second;
                    
                    if(dist[wNode] > curD + wDist) {
                        dist[wNode] = curD + wDist;
                        pq.push({dist[wNode], wNode});
                    }
                }
            }    
        }
        
        return;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    
        int ans = 0;
        
        // 3rd arg - weight
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &x : times) {
            
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            
            // u -> v with weight wt
            adj[u].push_back({v, wt});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        
        // Using Dijkstra Algorithm 
        dijkstra(k, adj, dist);
        
        for(int i=1; i<=n; i++) {
            
            if(i != k && dist[i] == INT_MAX)                return -1;
            else                                            ans = max(ans, dist[i]);
        }
        
        return ans;
    }
    
};