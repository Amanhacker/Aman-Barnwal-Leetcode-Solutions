class Solution {
public:
    
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    
        int res = 0;
        vector<vector<int>> adj;             // 1st arg - node1, 2nd arg - no.of new nodes, value - node2
        
        adj.resize(n, vector<int>(n, -1));
        
        for(int i=0; i<edges.size(); i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            int c = edges[i][2];
            
            // c new nodes is to be added between node u and node v
            adj[u][v] = c;
            adj[v][u] = c;
        }
        
        vector<int> vis(n, 0);
        
        // Max heap on basis of maxMoves
        priority_queue<pair<int, int>> pq;
        
        pq.push({maxMoves, 0});
        
        while(pq.empty() == false) {
            
            pair<int, int> cur = pq.top();
            pq.pop();
            
            int maxMovesRemaining = cur.first;
            int nearestNodeId = cur.second;
            
            if(vis[nearestNodeId] == 1)                                         continue;
            
            // if node is unvisited, make it visited and increment the res
            vis[nearestNodeId] = 1;
            res++;
            
            // Iterating over all the nodes
            for(int i=0; i<n; i++) {
                
                // if there exists an edge between nearestNodeId and node i
                if(adj[nearestNodeId][i] != -1) {
                    
                    // if neighbour i has not been visited in past
                    if(vis[i] == 0 && maxMovesRemaining >= adj[nearestNodeId][i] + 1) {
                        pq.push({maxMovesRemaining - adj[nearestNodeId][i] - 1, i});
                    }
                    
                    int movesCost = min(maxMovesRemaining, adj[nearestNodeId][i]);
                    
                    // Reduce the movesCost in the distance between nearestNodeId and node i
                    adj[nearestNodeId][i] -= movesCost;
                    adj[i][nearestNodeId] -= movesCost;
                    
                    res += movesCost;
                }
            }
        
        }
        
        return res;
    }
    
};