class Solution {
public:
    
    // Possible movements are up, right, down, left
    // (-1, 0), (0, 1), (1, 0), (0, -1)
    
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};

    string s[4] = {"U", "R", "D", "L"};
    
    bool isValid(int x, int y, int n, int m, vector<vector<int>> &grid) {
        
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)             return true;
        else                                                                  return false;
    }
    
    void dfs(int x, int y, int n, int m, vector<vector<int>> &grid, string &str) {
       
        // Base Condition
        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0)             return;
        
        grid[x][y] = 0;
        
        for(int i=0; i<4; i++) {

            int x1 = x + dx[i];
            int y1 = y + dy[i];

            // if(isValid(x1, y1, n, m, grid) == true) {

                str += s[i];
                dfs(x1, y1, n, m, grid, str);
            // }
        }

        return;
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
    
        int res = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        set<string> w;
        
        // BFS on 2D Grid
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                if(grid[i][j] == 1) {
                    
                    // Run DFS from (i, j)
                    string str = "";
                    dfs(i, j, n, m, grid, str);

                    w.insert(str);
                }
            }
        }
        
        res = w.size();
        return res;
    }
    
};