class Solution {
public:
    
    
    
    void bfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &informTime, int &n, unordered_map<int, int> &u) {
                
        vector<int> vis(n ,0);
        queue<int> q;
        
        q.push(node);
        vis[node] = 0;
        
        while(q.empty() == false) {
            
            int n1 = q.size();
            
            // All nodes at one level
            int maxi = INT_MIN;
            
            while(n1--) {
            
                int temp = q.front();
                q.pop();
                
                // maxi = max(maxi, informTime[temp]);
                u[temp] += informTime[temp];
                
                for(auto &ch : adj[temp]) {
                    
                    if(vis[ch] == 0) {
                        vis[ch] = 1;
                        
                        u[ch] += u[temp];
                        q.push(ch);
                    }
                }
            }
        }
        
        return;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    
        int time = 0;
        
        // Form the graph
        unordered_map<int, vector<int>> adj;
        
        for(int i=0; i<manager.size(); i++) {
            // manager[i] -> i
            adj[manager[i]].push_back(i);
        }
        
        // 1st arg - node, 2nd arg - time
        unordered_map<int, int> u;
            
        bfs(headID, adj, informTime, n, u);
        
        for(auto &x : u) {
            if(time <= x.second) {
                time = x.second;
            }            
        }
        
        return time;
    }
    
};