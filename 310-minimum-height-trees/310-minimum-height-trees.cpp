class Solution {
public:
   
    void bfs(int n, unordered_map<int, vector<int>> &adj, vector<int> &degree, vector<int> &res) {
        
        queue<int> q;
        
        for(int i=0; i<n; i++) {
            
            if(degree[i] == 1) {
                q.push(i);
                degree[i]--;
            }
        }
        
        while(q.empty() == false) {
            
            int siz = q.size();
            res.clear();
            
            for(int i=0; i<siz; i++) {
                
                int temp = q.front();
                q.pop();
                
                res.push_back(temp);
                
                for(auto &ch : adj[temp]) {
                    degree[ch]--;
                    if(degree[ch] == 1)            q.push(ch);
                }
            }
        }
        
        if(n == 1)                                 res.push_back(0);
        
        return;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    
        vector<int> res, degree(n, 0);
        unordered_map<int, vector<int>> adj;
        
        for(auto &x : edges) {
            
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            
            degree[x[0]]++;
            degree[x[1]]++;
        }
        
        bfs(n, adj, degree, res);        
        
        return res;
    }
    
};