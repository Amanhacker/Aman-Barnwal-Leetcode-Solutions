class Solution {
public:
    
    // Possible movements are : top, right, down, left
    // (-1, 0), (0, 1), (1, 0), (0, -1)
    
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    
    bool isValid(int x, int y, int n, int m, vector<vector<int>> &vis) {
        
        if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0)            return true;
        else                                                                return false;
    }
    
    void dfs(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &h) {
        
        if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == 1)                return;
        
        vis[x][y] = 1;
        
        // Originally (x, y) to (x1, y1), then water will only flow iff h[x][y] >= h[x1][y1]
        // But we start from opposite i.e from edges, so condition reverses i.e h[x1][y1] >= h[x][y]
        
        for(int i=0; i<4; i++) {
            
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            
            if(isValid(x1, y1, n, m, vis) == true && h[x1][y1] >= h[x][y]) {
                dfs(x1, y1, n, m, vis, h);
            }
        }
        
        return;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
    
        vector<vector<int>> res;
        vector<int> temp;
        
        int n = h.size();
        int m = h[0].size();
        
        if(n == 0)                                  return res;
        
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++) {
            dfs(i, 0,   n, m, pacific, h);                   // For Pacific Edge - Left
            dfs(i, m-1, n, m, atlantic, h);                  // For Atlantic Edge - Right
        }
        
        for(int j=0; j<m; j++) {
            dfs(0,   j, n, m, pacific, h);                   // For Pacific Edge - Top
            dfs(n-1, j, n, m, atlantic, h);                  // For Atlantic Edge - Bottom
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                if(pacific[i][j] == 1 && atlantic[i][j] == 1)         res.push_back({i, j});
            }
        }
        
        return res;
    }
    
};