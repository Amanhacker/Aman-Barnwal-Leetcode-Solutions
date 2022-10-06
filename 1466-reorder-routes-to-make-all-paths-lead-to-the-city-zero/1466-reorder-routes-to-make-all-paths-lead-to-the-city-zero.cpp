class Solution {
public:
    
    // Using BFS - O(n)
    
    void bfs(int node, unordered_map<int, vector<int>> adj, unordered_map<int, vector<int>> back, vector<int> &vis, int &res) {
                
        queue<int> q;
        
        q.push(node);
        
        vis[node] = 1;

        while(q.empty() == false) {
            
            int temp = q.front();
            q.pop();
            
            // Change dir for all arrows facing out
            for(int i=0; i<adj[temp].size(); i++) {
                
                // If there is a forward edge
                int child = adj[temp][i];
                
                if(vis[child] == 0) {
                    
                    q.push(child);
                    vis[child] = 1;
                    
                    res++;
                }
            }
            
            // Push other nodes so we visit everything
            for (int i=0; i<back[temp].size(); i++){
                
                int child = back[temp][i];
                
                if(vis[child] == 0) {
                    q.push(child);
                    vis[child] = 1;
                }
            }
        }
        
        return;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
    
        int res = 0;
        unordered_map<int, vector<int>> adj, back;
        
        for(int i=0; i<connections.size(); i++) {
            
            int u = connections[i][0];
            int v = connections[i][1];
            
            // Road from city u to city v
            adj[u].push_back(v);
            back[v].push_back(u);
        }
        
        vector<int> vis(n, 0);
        
        // Start bfs from node 0
        
        // Start at city 0, recursively go at each level.
        // And if there found a forward or outgoing edge just increament the res
        bfs(0, adj, back, vis, res);
        
        return res;
    }
    
};