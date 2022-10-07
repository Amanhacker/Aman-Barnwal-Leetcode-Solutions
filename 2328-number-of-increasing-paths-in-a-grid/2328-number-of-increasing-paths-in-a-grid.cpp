class Solution {
public:
   
    const int mod = 1e9 + 7;
    
     // Top, right, down, left
    // (-1, 0), (0, 1), (1, 0), (0, -1)
    
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    
    bool isValid(int x, int y, int n, int m) {
        if(x >= 0 && x < n && y >= 0 && y < m)              return true;
        else                                                return false;
    }

    // Here, dp[x][y] gives us the length of longest increasing path starting from (x, y)
    int dfs(int x, int y, int n, int m, vector<vector<int>> &dp, vector<vector<int>> &grid) {
        
        if(dp[x][y] != -1)                                  return dp[x][y];
        
        // Since, a number itself is a path
        dp[x][y] = 1;
        
        for(int k=0; k<4; k++) {
            
            int x1 = x + dx[k];
            int y1 = y + dy[k];
            
            if(isValid(x1, y1, n, m) == true && grid[x1][y1] > grid[x][y]) {
                
                dp[x][y] += dfs(x1, y1, n, m, dp, grid) % mod;
                dp[x][y] %= mod;
            }
        }
        
        return dp[x][y] % mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
    
        int res = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        // No. of strictly increasing paths in the grid
        
        // Here, dp[i][j] gives us the no of longest increasing path starting from (i, j)
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                res += dfs(i, j, n, m, dp, grid) % mod;
                res %= mod;
            }
        }
        
        return res;
    }
    
};