class Solution {
public:
    
    // Top, right, down, left
    // (-1, 0), (0, 1), (1, 0), (0, -1)
    
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    
    bool isValid(int x, int y, int n, int m) {
        
        if(x >= 0 && x < n && y >= 0 && y < m)                                             return true;
        else                                                                               return false;
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    
        vector<int> res;
    
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                int tempEle = mat[i][j];
                int maxi = INT_MIN;

                for(int k=0; k<4; k++) {
                    
                    int x1 = i + dx[k];
                    int y1 = j + dy[k];

                    if(isValid(x1, y1, n, m) == true) {
                        maxi = max(maxi, mat[x1][y1]);
                    }
                }
                
                if(tempEle > maxi) {

                    res.push_back(i);
                    res.push_back(j);

                    return res;
                 }
            }
        }
        
        return res;
    }
    
};