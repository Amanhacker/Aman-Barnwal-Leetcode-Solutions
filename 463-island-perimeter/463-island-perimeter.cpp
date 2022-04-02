class Solution {
public:
    
    vector<vector<int>> grid;
    int n, m;
    
    int dx[4] = {1, 0, -1,  0};
    int dy[4] = {0, 1,  0, -1};
    
    bool isValid(int x, int y) {
        if(x >= 0 && x < n && y >= 0 && y < m)                      return true;
        else                                                        return false;
    }
    
    int noSurroundedByWater(int x, int y) {
        
        int count = 0;
        
        for(int i=0; i<4; i++) {
            
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            
            if(isValid(x1, y1) == true) {
                if(grid[x1][y1] == 1)                                  count++;
            }
        }
        
        return (4 - count);
    }
    
    int islandPerimeter(vector<vector<int>>& _grid) {
        
        // 1 means land and 0 means water
        
        n = _grid.size();
        m = _grid[0].size();
        
        grid.resize(n, vector<int>(m));
        grid = _grid;
        
        int peri = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                if(grid[i][j] == 1)             peri += noSurroundedByWater(i, j);
            }
        }
        
        return peri;
    }
    
};