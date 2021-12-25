class Solution {
public:

    // All directions : right, down, up, left
    // (0, 1), (1, 0), (-1, 0), (0, -1)
    
    int dx[4] = {0, 1, -1,  0};
    int dy[4] = {1, 0,  0, -1};
    
    bool flag = true;
    
    void dfs(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid) {
        
        // Base Condition
        if(x < 0 || x > n || y < 0 || y > m || grid[x][y] == 1 || vis[x][y] == 1)             return;
        
        // if cell with value 0 lies on boundary rows and columns, then don't include this connected component of 0's
        if( (x == 0 || x == n-1 || y == 0 || y == m-1) && grid[x][y] == 0) {
            flag = false;
            return;
        }   
        
        vis[x][y] = 1;
        
        for(int i=0; i<4; i++) {
            dfs(x + dx[i], y + dy[i], n, m, vis, grid);
        }
        
        return;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
    
        int count = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // You cannot start from boundary rows and columns since the cell have to be surrounded by all 1's
        for(int i=1; i<=n-2; i++) {
            for(int j=1; j<=m-2; j++) {
                
                flag = true;
                
                if(grid[i][j] == 0 && vis[i][j] == 0) {
                     
                    dfs(i, j, n, m, vis, grid);
                    
                    // Increment the count only if the no any cell of this connected component lies on boundary rows and columns
                    if(flag == true)                            count++;
                }
            }
        }
        
        return count;
    }
    
};