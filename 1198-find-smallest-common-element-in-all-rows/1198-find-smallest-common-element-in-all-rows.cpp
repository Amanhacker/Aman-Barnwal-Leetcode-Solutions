class Solution {
public:
    
    int smallestCommonElement(vector<vector<int>>& mat) {
    
        int n = mat.size();
        int m = mat[0].size();
        
        map<int, int> mp;
        
        for(int i=0; i<n; i++) {
            
            map<int, int> u;
            
            for(int j=0; j<m; j++)                              u[mat[i][j]]++;                
            
            for(auto &x : u) {
               
                if(x.second >= 1)                               mp[x.first]++;
                if(mp[x.first] == n)                            return x.first;
            }
        }
        
        return -1;
    }
    
};