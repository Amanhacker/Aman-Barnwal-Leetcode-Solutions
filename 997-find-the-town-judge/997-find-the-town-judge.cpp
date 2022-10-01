class Solution {
public:
    
    int findJudge(int n, vector<vector<int>>& trust) {
    
        vector<int> indegree(n + 1), outdegree(n + 1);
        
        for(auto &x : trust) {
            
            int u = x[0];
            int v = x[1];
            
            // u trust v i.e u -> v
            indegree[v]++;
            outdegree[u]++;
        }
        
        for(int i=1; i<=n; i++) {
            if(indegree[i] == n - 1 && outdegree[i] == 0)       return i;
        }
        
        return -1;
    }
    
};