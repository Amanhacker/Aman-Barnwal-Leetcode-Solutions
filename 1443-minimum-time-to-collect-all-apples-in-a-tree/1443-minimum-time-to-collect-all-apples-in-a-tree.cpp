class Solution {
public:
    
    pair<int, int> dfs(int node, int par, unordered_map<int, vector<int>> &adj, vector<bool> &hasApple) {
        
        pair<int, int> v = {0, hasApple[node]};
        
        for(auto &ch : adj[node]) {
            
            if(ch != par) {             // move forward always
                
                pair<int, int> x = dfs(ch, node, adj, hasApple);
                
                v.first += (2 + x.first) * x.second;
                v.second |= x.second; 
            }
        }
        
        return v;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    
        int time = 0;
        unordered_map<int, vector<int>> adj;
        
        for(auto &x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }        
        
        time += dfs(0, -1, adj, hasApple).first;
        return time;
    }
    
};