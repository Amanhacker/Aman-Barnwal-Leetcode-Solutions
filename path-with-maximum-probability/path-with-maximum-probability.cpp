class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    
        double res;
        
        // Use Dijkstra Algorithm with some modification using Max Heap
        
        unordered_map<int, vector<pair<double, int>>> adj;
        
        for(int i=0; i<edges.size(); i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            
            // Undirected edge between node u and v with probability succProb
            adj[u].push_back({wt, v});
            adj[v].push_back({wt, u});
        }
        
        // Use Maximum Heap
        priority_queue<pair<double, int>> pq;               // 1st arg - Prob, 2nd arg - Node
        
        vector<double> dist(n, 0.0);
        
        pq.push({1.0, start});
        dist[start] = 1;
        
        while(pq.empty() == false) {
            
            pair<double, int> cur = pq.top();
            pq.pop();
            
            int cur_node = cur.second;
            double cur_wt = cur.first;
            
            for(int i=0; i<adj[cur_node].size(); i++) {
                
                pair<double, int> w = adj[cur_node][i];
                
                int w_node = w.second;
                double w_wt = w.first;
                
                if(dist[w_node] < cur_wt * w_wt) {
                    
                    dist[w_node] = cur_wt * w_wt;
                    pq.push({dist[w_node], w_node});
                }
            }
            
        }
        
        res = dist[end];
        return res;
    }
    
};