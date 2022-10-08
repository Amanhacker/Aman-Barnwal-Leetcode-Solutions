class Solution {
public:

    void dfs(int node, vector<int> &vis, unordered_map<int, vector<int>> &adj, int &countNodes) {
        
        vis[node] = 1;
        countNodes++;
        
        for(auto &ch : adj[node]) {
            if(vis[ch] == 0) {
                dfs(ch, vis, adj, countNodes);
            }
        }
        
        return;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
    
        int res = 0;
        
        // Build a graph with bombs as node, and the neighbour of bombs are the nodes which can be detonated by this bomb
        
        unordered_map<int, vector<int>> adj;
        int n = bombs.size();
        
        for(int i=0; i<bombs.size()-1; i++) {
            for(int j=i+1; j<bombs.size(); j++) {
                        
                long long int x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
                long long int x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                
                long long int dSq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                
                // Check whether bomb i can detonate bomb j 
                // For this, dSq is less than r1 * r1
                
                if(dSq <= r1 * r1) {
                    // Bomb i can detonate bomb j
                    adj[i].push_back(j);
                }
                
                if(dSq <= r2 * r2) {
                    // Bomb j can detonate bomb i
                    adj[j].push_back(i);
                }
            }
        }
        
        
        for(int i=0; i<n; i++) {

            vector<int> vis(n, 0);
            
            int countNodes = 0;

            // Maximum no of nodes reachable from node i
            dfs(i, vis, adj, countNodes);
            res = max(res, countNodes);
        }
        
        return res;
    }
    
};