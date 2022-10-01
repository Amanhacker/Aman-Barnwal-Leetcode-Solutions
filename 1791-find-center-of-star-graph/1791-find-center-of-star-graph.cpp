class Solution {
public:
    
    int findCenter(vector<vector<int>>& edges) {
    
        vector<int> degree(100001);
        
        int maxi = INT_MIN;
        
        for(auto &x : edges) {
           
            int u = x[0];
            int v = x[1];
            
            // Undirected edge between u and v i.e u <-> v
            degree[u]++;
            degree[v]++;

            maxi = max(maxi, max(u, v));
        }
        
        int n = maxi;
        
        for(int i=1; i<=n; i++) {
            if(degree[i] ==  n - 1)             return i;
        }
        
        return -1;
    }
    
};