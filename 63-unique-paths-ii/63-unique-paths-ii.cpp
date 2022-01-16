class Solution {
public:
    
    // Using DP
   
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    
        int n = grid.size();
        int m = grid[0].size();
        
        if(n == 1 && m == 1)                                    return (grid[0][0] == 0);
        if(grid[0][0] == 1)                                     return 0;
        
        // Only movements are down and right
        
        // Source vertex is (0, 0) and destination vertex is (n-1, n-1)
        // Obstacle is 1, and space is 0
        
        // Find the no.of paths to reach the destination
        
        vector<vector<int>> dp;
        dp.resize(n, vector<int>(m));
        
        // Fill the 1st column
        for(int i=0; i<n; i++) {
            if(grid[i][0] == 1) {
                for(int k=i; k<n; k++)                              dp[k][0] = 0;
                break;
            }
            else                                                    dp[i][0] = 1;
        }
        
        // Fill the 1st row
        for(int j=0; j<m; j++) {
            if(grid[0][j] == 1) {
                for(int k=j; k<m; k++)                              dp[0][k] = 0;
                break;
            }
            else                                                    dp[0][j] = 1;
        }
        
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(grid[i][j] == 1)                                 dp[i][j] = 0;
                else                                                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[n-1][m-1];
    }
    
};