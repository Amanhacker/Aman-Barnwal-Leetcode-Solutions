class Solution {
public:

    set<int> cycleNodes, safeNodes;
    
    // Return true, if node is a safe node 
    // If it contains a cycle, then return false
    
    bool dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &vis) {
        
        if(cycleNodes.find(node) != cycleNodes.end())               return false;
        if(safeNodes.find(node) != safeNodes.end())                 return true;
        
        if(vis[node] == 1) {
            cycleNodes.insert(node);
            return false;
        }
        
        // Make node visited
        vis[node] = 1;
        
        for(auto &ch : adj[node]) {
            
            if(dfs(ch, adj, vis) == 0) {
                cycleNodes.insert(ch);
                return false;
            }
        }
        
        safeNodes.insert(node);
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    
        vector<int> res;
        int n = graph.size();
        
        unordered_map<int, vector<int>> adj;
        vector<int> vis(n, 0);
        
        for(int i=0; i<graph.size(); i++) {
            for(auto &x : graph[i]) {

                adj[i].push_back(x);
            }   
        }
        
        for(int i=0; i<n; i++) {
            if(dfs(i, adj, vis) == true)         res.push_back(i);
        }
        
        return res;
    }
    
};