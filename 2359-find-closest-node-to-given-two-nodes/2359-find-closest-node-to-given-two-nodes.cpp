class Solution {
public:
   
    void bfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &dist, vector<int> &vis) {
        
        queue<int> q;
        q.push(node);
        
        vis[node] = 1;
        dist[node] = 0;
        
        while(q.empty() == false) {
            
            int n = q.size();
            
            while(n--) {
                
                int temp = q.front();
                q.pop();
                
                for(auto &ch : adj[temp]) {
                    if(vis[ch] == 0) {
                        
                        q.push(ch);
                        
                        dist[ch] = dist[temp] + 1;
                        vis[ch] = 1;
                    }
                }
            }
        }
        
        return;
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    
        unordered_map<int, vector<int>> adj;
        
        for(int i=0; i<edges.size(); i++) {
            // i -> edges[i]
            if(edges[i] != -1)              adj[i].push_back(edges[i]);
        }
        
        int n = edges.size();
        
        // Shortest distance from node1 and node2 individually to each node
        vector<int> dist1(n, -1), dist2(n, -1), vis(n, 0);
        bfs(node1, adj, dist1, vis);
        
        for(int i=0; i<n; i++)                  vis[i] = 0;
        bfs(node2, adj, dist2, vis);
        
        int minDist = INT_MAX, res = -1;
        
        for(int i=0; i<n; i++) {

            if(min(dist1[i], dist2[i]) >= 0) {
               
                int temp = max(dist1[i], dist2[i]);
            
                if(temp < minDist) {
                    minDist = temp;
                    res = i;
                }
            }
        }
        
        return res;
    }
    
};