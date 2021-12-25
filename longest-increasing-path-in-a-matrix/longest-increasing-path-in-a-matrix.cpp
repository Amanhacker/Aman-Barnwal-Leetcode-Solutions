class Solution {
public:
    
    // Using Memoization
    
    // up, right, down, left
    // (-1, 0), (0, 1), (1, 0), (0, -1)
    
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    
    bool isValid(int x, int y, int n, int m) {
        if(x >= 0 && x < n && y >= 0 && y < m)                          return true;
        return false;
    }

    int longestHelperPath(int x, int y, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        
        if(dp[x][y] != -1)                                              return dp[x][y];
        
        int maxi = 0;
        
        for(int i=0; i<4; i++) {
            
            int tempX = x + dx[i];
            int tempY = y + dy[i];
            
            if(isValid(tempX, tempY, n, m) == true && grid[tempX][tempY] > grid[x][y]) {
                maxi = max(maxi, longestHelperPath(tempX, tempY, n, m, grid, dp));
            }
        }
        
        maxi = maxi + 1;
        
        dp[x][y] = maxi;
        return maxi;
    }
    
    int longestIncreasingPath(vector<vector<int>>& grid) {
    
        int res = INT_MIN;
        
        int n = grid.size();
        int m = grid[0].size();
        
        // Find the longest increasing path in the grid and returns its length
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                res = max(res, longestHelperPath(i, j, n, m, grid, dp));
            }
        }
        
        
        
        
        return res;
    }
    
};