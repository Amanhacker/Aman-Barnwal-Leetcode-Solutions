class Solution {
public:
   
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &vis) {
        
        for(auto &ch : adj[node]) {
           
            if(vis[ch] == 0) {
                vis[ch] = 1;
                dfs(ch, adj, vis);
            }
        }
        
        return;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
    
        unordered_map<int, vector<int>> adj;
        int n = rooms.size();
        
        vector<int> vis(n, 0), indegree(n, 0);
        
        for(int i=0; i<n; i++) {
            for(auto &x : rooms[i]) {
                
                adj[i].push_back(x);                // i -> x
                indegree[x]++; 
            }
        }
        
        // 1 means unlocked
        vis[0] = 1;
        
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                dfs(i, adj, vis);
            }
        }
        
        for(auto &x : vis) {
            if(x == 0)                                      return false;
        }
        
        return true;
    }
    
};