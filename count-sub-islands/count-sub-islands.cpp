class Solution {
public:
    
    // All 4 directions : up, right, down, left
    // (-1, 0), (0, 1), (1, 0), (0, -1)
    
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    
    bool res;
    
    bool isValid(int x, int y, int n, int m, vector<vector<int>> grid) {
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)                                  return true;
        return false;
    }
    
    // Using DFS on 2D Grid
    
    void dfs(int x, int y, int n, int m, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
    
        // if there is water on  grid1 for the location on B then our current island can't be counted and so we mark res as false 
        if(x<0 || x>=n || y<0 || y>=m || grid2[x][y]!=1)  //Boundary case for matrix
            return ;
        
        if(grid1[x][y] == 0) {
            res = false;
            return;
        }
        
        // Mark current cell as visited
        grid2[x][y] = 0;
        
        // Make recursive call in all 4 adjacent directions
        
        for(int i=0; i<4; i++) {
            
            int wX = x + dx[i];
            int wY = y + dy[i];
            
            // if(isValid(wX, wY, n, m, grid2) == true) {
                dfs(wX, wY, n, m, grid1, grid2);
            //}
        }
        
        return;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int no_of_islands = 0;              // No.of islands of grid2 that are also subislands of grid1 islands
        
        int n1 = grid1.size();
        int m1 = grid1[0].size();
        
        if(n1 == 0)                                     return 0;
        
        // DFS on Grid2 
        
        for(int i=0; i<n1; i++) {
            for(int j=0; j<m1; j++) {
                
                if(grid2[i][j] == 1){
                    
                    res = true;
                    dfs(i, j, n1, m1, grid1, grid2);
                    
                    //if current island of grid2 meets the requirement update the no of islands
                    if(res == true)                                     no_of_islands += 1;
                }
            }
        }
		
        return no_of_islands;
    }
    
};