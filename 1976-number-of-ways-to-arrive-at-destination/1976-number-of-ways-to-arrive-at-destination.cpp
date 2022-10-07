class Solution {
public:
    
   const int mod = 1e9 + 7;
    
    int countPaths(int n, vector<vector<int>>& roads) {
    
        int count = 0;
        
        if(n == 0)                                       return count;
        
        unordered_map<int, vector<pair<long long, int>>> adj;            // 1st arg - src, 2nd arg - weight, 3rd arg - dest
        
        for(int i=0; i<n; i++)                           adj[i].clear();

        for(auto &x : roads) {
            adj[x[0]].push_back({x[2], x[1]});
            adj[x[1]].push_back({x[2], x[0]});
        }
        
        // Form a Min Heap
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        vector<long long> dist(n, LONG_MAX);
        vector<int> path(n, 0);
        
        pq.push({0, 0});

        dist[0] = 0;
        path[0] = 1;
        
        while(pq.empty() == false) {
            
            pair<long long, int> cur = pq.top();
            pq.pop();
            
            int curNode = cur.second;
            long long curWeight = cur.first;
            
            for(int i=0; i<adj[curNode].size(); i++) {
                
                pair<long long, int> w = adj[curNode][i];
                
                int wNode = w.second;
                long long wWeight = w.first;
                
                if(dist[wNode] > curWeight + wWeight) {
                    
                    dist[wNode] = curWeight + wWeight;
                    
                    pq.push({dist[wNode], wNode});
                    path[wNode] = path[curNode] % mod;
                }
                
                else if(dist[wNode] == curWeight + wWeight) {
                    path[wNode] += path[curNode];
                    path[wNode] %= mod;
                }
            }
        }
        
        count = path[n-1];
        return count;
    }
    
};