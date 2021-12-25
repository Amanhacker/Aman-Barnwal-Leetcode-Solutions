class Solution {
public:
    
    // All 4 directions : up, right, down, left
    // (-1, 0), (0, 1), (1, 0), (0, -1)
    
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    
    bool isValid(int x, int y, vector<vector<int>> &vis, vector<vector<char>> &grid, int n, int m) {
        
        if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && grid[x][y] == '1')         return true;
        return false;
    }
    
    void bfs(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        
        queue<pair<int, int>> q;
        q.push({x, y});
        
        while(q.empty() == false) {
            
            pair<int, int> temp = q.front();
            q.pop();
            
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
    
    int numIslands(vector<vector<char>>& grid) {
    
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int count = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1' && vis[i][j] == 0) {
                    bfs(i, j, n, m, vis, grid);            
                    count++;
                }
            }
        }
        
        
        return count;
    }
    
};