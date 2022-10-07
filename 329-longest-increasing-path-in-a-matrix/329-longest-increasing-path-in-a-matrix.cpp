class Solution {
public:
    
    // Top, right, down, left
    // (-1, 0), (0, 1), (1, 0), (0, -1)
    
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    
    bool isValid(int x, int y, int n, int m) {
        if(x >= 0 && x < n && y >= 0 && y < m)              return true;
        else                                                return false;
    }
    
    int dfs(int x, int y, int n, int m, vector<vector<int>> &dp, vector<vector<int>> &mat) {
        
        int maxi = 0;
        
        if(dp[x][y] != -1)                              return dp[x][y];
        
        for(int k=0; k<4; k++) {
            
            int x1 = x + dx[k];
            int y1 = y + dy[k];
            
            if(isValid(x1, y1, n, m) == true && mat[x1][y1] > mat[x][y]) {
                maxi = max(maxi, dfs(x1, y1, n, m, dp, mat));
            }
        }
        
        maxi += 1;
        dp[x][y] = maxi;
        
        return dp[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
    
        int res = INT_MIN;
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {

                // Start from location (i, j)
                res = max(res, dfs(i, j, n, m, dp, mat));
            }
        }
        
        return res;
    }
    
};