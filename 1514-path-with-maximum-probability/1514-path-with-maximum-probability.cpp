class Solution {
public:
    
    void dijkstra(int node, vector<double> &dist, unordered_map<int, vector<pair<int, double>>> &adj) {
        
        // Max Heap
        priority_queue<pair<double, int>> pq;
        
        pq.push({1.0, node});
        dist[node] = 0.0;
        
        while(pq.empty() == false) {
            
            int n = pq.size();
            
            while(n--) {
                
                pair<double, int> cur = pq.top();
                pq.pop();
                
                double curWt = cur.first;
                int curNode = cur.second;
                
                for(auto &ch : adj[curNode]) {
                    
                    double chWt = ch.second;
                    int chNode = ch.first;
                    
                    if(dist[chNode] < chWt * curWt) {
                        dist[chNode] = chWt * curWt;
                        pq.push({dist[chNode], chNode});
                    }
                }
            }
        }
        
        return;
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    
        unordered_map<int, vector<pair<int, double>>> adj;
        
        for(int i=0; i<edges.size(); i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }
        
        vector<double> dist(n, 0.0);
        
        dijkstra(start, dist, adj);
        
        return dist[end];
    }
    
};