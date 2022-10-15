class Solution {
public:
    
    int edgeScore(vector<int>& edges) {
    
        int res;
        unordered_map<int, vector<int>> adj;
        
        int n = edges.size();
        
        // Build the Directed Graph
        
        for(int i=0; i<n; i++) {

            // Reverse the edge, so that it would be easy to find the score
            // edges[i] -> i
            
            adj[edges[i]].push_back(i);
        }
        
        // 1st arg - node, 2nd arg - score of this node
        unordered_map<int, long long int> u;
        
        for(int i=0; i<n; i++) {
            
            long long int score = 0;
            
            // Find the score of each node i
            for(auto &x : adj[i])               score += x;
            
            u[i] = score;
        }
        
        long long int scoreMax = LONG_MIN;
        
        for(auto &x : u) {
            
            if(x.second > scoreMax) {
                scoreMax = x.second;
                res = x.first;
            }
            
            else if(x.second == scoreMax) {
                scoreMax = x.second;
                res = min(res, x.first);
            }
        }
        
        return res;
    }
    
};