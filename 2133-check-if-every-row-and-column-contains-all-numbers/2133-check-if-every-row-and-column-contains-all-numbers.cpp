class Solution {
public:
    
    bool checkValid(vector<vector<int>>& mat) {
    
        int n = mat.size();
        
        for(int i=0; i<n; i++) {
            
            map<int, int> u1, u2;
            
            for(int j=0; j<n; j++) {
                u1[mat[i][j]]++;
                u2[mat[j][i]]++;
            }
            
            for(int k=1; k<=n; k++) {
                if(u1[k] == 0 || u2[k] == 0)                          return false;
            }
        }
        
        return true;
    }
    
};