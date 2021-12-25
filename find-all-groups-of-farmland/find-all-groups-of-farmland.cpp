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
    
    void bfs(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<vector<int>> &res) {
        
        int x_min = n-1, y_min = m-1;
        int x_max = 0, y_max = 0;
        
        vector<int> path;
        queue<pair<int, int>> q;
        
        q.push({x, y});
        vis[x][y] = 1;
        
        while(q.empty() == false) {
            
            pair<int, int> temp = q.front();
            q.pop();

            x_min = min(x_min, temp.first);
            y_min = min(y_min, temp.second);
            
            x_max = max(x_max, temp.first);
            y_max = max(y_max, temp.second);
            
            for(int i=0; i<4; i++) {
              
                int wX = temp.first + dx[i];
                int wY = temp.second + dy[i];
                
                if(isValid(wX, wY, vis, grid, n, m) == true) {
                    q.push({wX, wY});
                    vis[wX][wY] = 1;
                }
            }
        }
        
        path.push_back(x_min);
        path.push_back(y_min);
        path.push_back(x_max);
        path.push_back(y_max);
        
        res.push_back(path);
        path.clear();
        
        return;
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
    
        vector<vector<int>> res;
        vector<int> path;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    bfs(i, j, n, m, vis, grid, res);
                }
            }
        }
            
        return res;
    }
    
};