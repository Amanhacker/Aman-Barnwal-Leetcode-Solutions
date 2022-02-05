class Solution {
public:

    bool isValid(int x, int y, int n, int m) {
        if(x >= 0 && x < n && y >= 0 && y < m)          return true;
        else                                            return false;
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    
        vector<vector<int>> res;
        
        int n = mat.size();
        int m = mat[0].size();
        
        res.resize(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                int sum = 0;
                
                // i = [i-k, i+k], j = [j-k, j+k]
                for(int i1=i-k; i1<=i+k; i1++) {
                    for(int j1=j-k; j1<=j+k; j1++) {
                        
                        if(isValid(i1, j1, n, m) == true) {
                            sum += mat[i1][j1];
                        }
                    }
                }
                
                res[i][j] = sum;
            }
        }
        
        return res;
    }
    
};