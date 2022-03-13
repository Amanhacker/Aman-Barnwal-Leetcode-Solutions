class Solution {
public:
    
    // Possible movements : top, right, bottom, left
    // (-1, 0), (0, 1), (1, 0), (0, -1)
    
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    
    void dfs(int x, int y, int n, int m, int last_x, int last_y, char ch, vector<vector<char>> &grid, vector<vector<int>> &vis, bool &flag) {

        if(flag == true)                                                                 return;
        
        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != ch)                       return;
        
        if(vis[x][y] == 1) {
            flag = true;
            return;
        }
        
        vis[x][y] = 1;
        
        for(int i=0; i<4; i++) {
            
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            
            // When (x1, y1) are not previous visited co-ordinates of (x, y)
            
            if(x1 != last_x || y1 != last_y) {
                dfs(x1, y1, n, m, x, y, ch, grid, vis, flag);
            }
        }
        
        return;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
    
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        bool flag = false;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                if(vis[i][j] == 0)                              dfs(i, j, n, m, -1, -1, grid[i][j], grid, vis, flag);
                if(flag == true)                                return true;
            }
        }
        
        return false;
    }
    
};