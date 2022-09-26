class Solution {
public:
    

    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    
    int obst = 0;

    bool isValid(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid) {

        if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && grid[x][y] != -1)                 return true;
        else                                                                                        return false;
    }

    void findAllPaths(int x, int y, int destX, int destY, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis, int &move, int &count) {

        if(x == destX && y == destY && move == n * m - obst) {

            // for(int i=0; i<n; i++) {
            //     for(int j=0; j<m; j++) {
            //         cout << vis[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
            // cout << endl;
            
            count++;
        }

        for(int k=0; k<4; k++) {

            int x1 = x + dx[k];
            int y1 = y + dy[k];

            if(isValid(x1, y1, n, m, vis, grid) == true) {

                move++;
                vis[x1][y1] = move;

                findAllPaths(x1, y1, destX, destY, n, m, grid, vis, move, count);

                move--;
                vis[x1][y1] = 0;
            }
        }

        return;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        // 1 - source, 2 - destination, 0 - space, -1 - obstacle
        
        int srcX, srcY, destX, destY;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                if(grid[i][j] == 2) {
                    destX = i;
                    destY = j;
                }
                
                else if(grid[i][j] == 1) {
                    srcX = i;
                    srcY = j;
                }
                
                else if(grid[i][j] == -1)                   obst++;
            }
        }
        
        if(grid[srcX][srcY] == -1)                          return 0;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int move = 1;
        vis[srcX][srcY] = 1;
        
        int count = 0;
        
        findAllPaths(srcX, srcY, destX, destY, n, m, grid, vis, move, count);
        
        return count;
    }
    
};