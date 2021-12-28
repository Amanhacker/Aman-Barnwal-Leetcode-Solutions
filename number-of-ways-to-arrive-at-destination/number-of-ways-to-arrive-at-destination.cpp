class Solution {
public:
    
    const int mod  = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& graph) {
        
        int count = 0;
        
        if(n == 0)                                                      return 0;

        unordered_map<int, vector<pair<long long, int>>> adj;
        
        for(int i=0; i<n; i++)                                          adj[i].clear();

        // Form the graph
        for(int i=0; i<graph.size(); i++) {

            vector<int> temp = graph[i];

            int node1 = temp[0];
            int node2 = temp[1];

            int wt = temp[2];
            
            // cout << node1 << " " << node2 << " " << wt << endl;
            
            // Edge between temp[0] and temp[1] takes time temp[2]
            adj[node1].push_back({wt, node2});
            adj[node2].push_back({wt, node1});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        vector<long long> dist(n, LONG_MAX);
        vector<int> path(n, 0);
        
        pq.push({0, 0});
        
        dist[0] = 0;
        path[0] = 1;

        // No.of ways to reach destination i.e (n - 1) from 0 in minimum time

        // Using Dijkstra Algorithm

        while(pq.empty() == false) {

            pair<long long, int> temp = pq.top();
            pq.pop();

            int cur_node = temp.second;
            long long cur_wt = temp.first;

            for(int i=0; i<adj[cur_node].size(); i++) {

                pair<long long, int> w = adj[cur_node][i];

                int w_node = w.second;
                long long w_wt = w.first;
                
                if(dist[w_node] > w_wt + cur_wt) {
                    
                    dist[w_node] = w_wt + cur_wt;
                    pq.push({dist[w_node], w_node});
                    
                    path[w_node] = path[cur_node] % mod;
                }
                
                else if(dist[w_node] == w_wt + cur_wt) {
                    path[w_node] += path[cur_node];
                    path[w_node] %= mod;
                }
            }
        }

//         for(auto &x : path)                                 cout << x << " ";
//         cout << endl;
        
//         for(auto &x : dist)                                 cout << x << " ";
//         cout << endl;
        
        count = path[n-1];
        return count;
    }
    
};