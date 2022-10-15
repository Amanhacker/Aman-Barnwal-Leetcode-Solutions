class Solution {
public:
    
    void dfs(char node1, char dest, unordered_map<char, vector<char>> &adj, unordered_map<char, int> &vis, bool &flag) {
        
        if(flag == true)                            return;
        
        vis[node1] = 1;
        
        if(node1 == dest) {
            flag = true;
            return;
        }
        
        for(auto &ch : adj[node1]) {
            if(vis[ch] == 0) {
                dfs(ch, dest, adj, vis, flag);
            }
        }
        
        return;
    }
    
    bool equationsPossible(vector<string>& equations) {
    
        unordered_map<char, vector<char>> adj;
        int n = equations.size();
        
        for(auto &x : equations) {
            
            string s = x;
            
            if(s[1] == '=') {
                adj[s[0]].push_back(s[3]);
                adj[s[3]].push_back(s[0]);
            }
        }
        
        for(auto &x : equations) {
            
            if(x[1] == '!') {
                
                char node1 = x[0];
                char node2 = x[3];
                
                // Check whether node1 and node2 are connected by any chance
                bool flag = false;
                unordered_map<char, int> vis;
                
                dfs(node1, node2, adj, vis, flag);
                vis.clear();
                
                if(flag == true)                        return false;
            }
        }
        
        return true;
    }
    
};