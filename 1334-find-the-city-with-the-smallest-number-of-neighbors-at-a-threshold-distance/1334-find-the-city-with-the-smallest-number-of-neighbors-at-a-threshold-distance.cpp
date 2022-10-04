class Solution {
public:
    
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
        
        if(a.first == b.first)                  return a.second > b.second;
        else                                    return a.first < b.first;
    }
   
    void dijkstra(vector<int> &dist, int node, unordered_map<int, vector<pair<int, int>>> &adj, int n) {
        
        // To find the min distance from a source vertex, use min heap
        
        // 1st arg - weight, 2nd arg - node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i=0; i<n; i++)                      dist[i] = INT_MAX;
        while(pq.empty() == false)                  pq.pop();

        pq.push({0, node});
        dist[node] = 0;
        
        while(pq.empty() == false) {
            
            int n1 = pq.size();
            
            while(n1--) {
                
                pair<int, int> cur = pq.top();
                pq.pop();
                
                int curNode = cur.second;
                int curD = cur.first;
                
                for(auto &x : adj[curNode]) {
                    
                    int wNode = x.first;
                    int wDist = x.second;
                    
                    if(dist[wNode] > curD + wDist) {
                        dist[wNode] = curD + wDist;
                        pq.push({dist[wNode], wNode});
                    }
                }
            }
        }
        
        return;
    }
    
    
    int findTheCity(int n, vector<vector<int>>& edges, int distTh) {
    
        int ans;
        
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &x : edges) {
            
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> dist(n, INT_MAX);
        
        // 1st arg - no of cities, 2nd arg - city no
        vector<pair<int, int>> v;
        
        for(int i=0; i<n; i++) {
            
            // Take i as source vertex
            dijkstra(dist, i, adj, n);
            
            int count = 0;
            
            for(int j=0; j<n; j++) {
                if(j != i && dist[j] <= distTh) {
                    count++;
                }
            }

            v.push_back({count, i});
        }
        
        sort(v.begin(), v.end(), cmp);
        auto it = v.begin();
        
        ans = it->second;
        return ans;
    }
    
};