class Solution {
public:
    
    set<int> cycleNodes, safeNodes;
    
    // If node is a safe node, then return true, else if it contains a cycle path, then return false
    bool dfs(int node, vector<int> &vis, vector<vector<int>> &adj) {
        
        // if node belongs to cycleNodes
        if(cycleNodes.find(node) != cycleNodes.end())                                   return false;
        
        // if node belongs to safeNodes
        if(safeNodes.find(node) != safeNodes.end())                                     return true;
        
        // if node is already visited i.e it contains a cycle, then return false
        if(vis[node] == 1) {
            cycleNodes.insert(node);
            return false;
        }
        
        // Make this node visited
        vis[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++) {
            
            int child = adj[node][i];
            
            if(dfs(child, vis, adj) == 0) {
                cycleNodes.insert(node) ;                                     // if child is in cycleNodes, then its par is also a cycleNode
                return false;
            }
        }
        
        safeNodes.insert(node);
        
        return true;        
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
    
        vector<int> res;
        int n = adj.size();
        
        vector<int> vis(n, 0);
        
        // Considering node i as the source vertex, if that path leads to a node whose outdegree  = 0, then push that node i in vector
        
        for(int i=0; i<n; i++) {
            if(dfs(i, vis, adj) == true)                                     res.push_back(i);
        }
        
        sort(res.begin(), res.end());
        return res;
    }
    
};