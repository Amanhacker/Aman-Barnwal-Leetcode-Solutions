class Solution {
public:

    // top, left, bottom, right
    // (-1, 0), (0, -1), (1, 0), (0, 1)
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    bool isValid(int r, int c, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid) {
    
        if(r >= 0 && r < n && c >= 0 && c < m && vis[r][c] == 0 && grid[r][c] == 1)                         return true;
        
        return false;
    }   
    
    void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> grid, int n, int m, int &count) {
        
        vis[r][c] = 1;
        
        queue<pair<int, int>> q;
        q.push({r, c});
        
        while(q.empty() == false) {
            
            pair<int, int> temp = q.front();
            q.pop();
            
            count++;
            
            for(int i=0; i<4; i++) {
                
                int tempX = temp.first + dx[i];
                int tempY = temp.second + dy[i];
            
                if(isValid(tempX, tempY, n, m, vis, grid) == true) {
                    q.push({tempX, tempY});
                    vis[tempX][tempY] = 1;
                }
            }
        }
        
        return;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    
        int area = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                if(vis[i][j] == 0 && grid[i][j] == 1) {
                    
                    int count = 0;
                    
                    bfs(i, j, vis, grid, n, m, count);
                    area = max(area, count);
                }
            }
        }
        
        return area;
    }
    
};