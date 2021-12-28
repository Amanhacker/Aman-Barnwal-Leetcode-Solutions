class Solution {
public:
    
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(int i=0; i<edges.size(); i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back({time, v});
            adj[v].push_back({time, u});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        vector<int> freq(n + 1, 0);
        
        bool flag = false;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 1});
        
        while(pq.empty() == false) {
            
            pair<int, int> cur = pq.top();
            pq.pop();
            
            int cur_node = cur.second;
            int cur_wt = cur.first;
            
            int signal = cur_wt / change;
            
            // For odd signal, it tends to red signal, but for even signal, it tends to green signal
            if(signal % 2 == 1) {
                cur_wt += (change * (signal + 1)) - cur_wt;
            }
            
            for(int i=0; i<adj[cur_node].size(); i++) {
                
                pair<int, int> w = adj[cur_node][i];
                
                int w_node = w.second;
                int w_wt = w.first;
                
                if(dist[w_node] != cur_wt + time && freq[w_node] < 2) {
                    
                    if(w_node == n && flag == true)                         return cur_wt + time;
                    
                    if(w_node == n)                                         flag = true;
                    
                    dist[w_node] = cur_wt + time;
                    freq[w_node]++;
                    
                    pq.push({cur_wt + time, w_node});
                    
                }
            }
        }
        
        return dist[n];
    }
    
};