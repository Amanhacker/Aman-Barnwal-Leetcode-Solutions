class Solution {
public:
    
    // All 4 directions : up, right, down, left
    // (-1, 0), (0, 1), (1, 0), (0, -1)
    
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    
    bool isValid(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m) {
        
        if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && grid[x][y] == 1)         return true;
        return false;
    }
    
    void bfs(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid, int &count) {
        
        queue<pair<int, int>> q;
        
        q.push({x, y});
        vis[x][y] = 1;
        
        while(q.empty() == false) {
            
            pair<int, int> temp = q.front();
            q.pop();
            
            count++;
            
            for(int i=0; i<4; i++) {
                
                int wX = temp.first + dx[i];
                int wY = temp.second + dy[i];
                
                if(isValid(wX, wY, vis, grid, n, m) == true) {
                    q.push({wX, wY});
                    vis[wX][wY] = 1;
                }
            }
        } 
        
        return;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    
        int n = grid.size();
        int m = grid[0].size();
        
        int maxArea = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                int count = 0;                      // No.of cells in an island i.e a connected component
                
                if(vis[i][j] == 0 && grid[i][j] == 1) {
                    bfs(i, j, n, m, vis, grid, count);
                    maxArea = max(maxArea, count);
                }
            }
        }
        
        return maxArea;
    }
    
};