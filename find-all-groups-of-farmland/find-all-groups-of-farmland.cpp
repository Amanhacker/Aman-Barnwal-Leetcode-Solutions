class Solution {
public:
    
    // Using DFS on 2D Grid
    
    // All 4 directions : up, right, down, left
    // (-1, 0), (0, 1), (1, 0), (0, -1)
    
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    
    void dfs(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid, int &x_max, int &y_max) {
        
        // Base Condition
        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || vis[x][y] == 1)         return;
        
        // Make the current node visited
        vis[x][y] = 1;
        
        x_max = max(x_max, x);
        y_max = max(y_max, y);
        
        for(int i=0; i<4; i++) {
            dfs(x + dx[i], y + dy[i], n, m, vis, grid, x_max, y_max);
        }
        
        return;
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
    
        vector<vector<int>> res;
        vector<int> path;
        
        int n = grid.size();
        int m = grid[0].size();
        
        int x_min, y_min, x_max, y_max;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                   
                    x_min = i;
                    y_min = j;
                    
                    x_max = i;
                    y_max = j;
                    
                    dfs(i, j, n, m, vis, grid, x_max, y_max);

                    path.push_back(x_min);
                    path.push_back(y_min);
                    path.push_back(x_max);
                    path.push_back(y_max);

                    res.push_back(path);
                    path.clear();
                }
            }
        }
            
        return res;
    }
    
};