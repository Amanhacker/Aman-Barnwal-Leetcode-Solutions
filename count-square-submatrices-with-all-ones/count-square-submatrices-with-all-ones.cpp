class Solution {
public:
    
    int countSquares(vector<vector<int>>& grid) {
    
        int count = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m));
        cout << n << " " << m << endl;
        
        // Initialize 1st row and 1st column
        
        for(int i=0; i<n; i++)                      dp[i][0] = grid[i][0];
        for(int j=1; j<m; j++)                      dp[0][j] = grid[0][j];
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                
                if(grid[i][j] == 1)                 dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                else                                dp[i][j] = 0;
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                count += dp[i][j];
            }
        }
        
        return count;
    }
    
};