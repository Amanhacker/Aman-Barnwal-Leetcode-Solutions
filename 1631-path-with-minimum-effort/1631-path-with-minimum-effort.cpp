class Solution {
public:
    
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    
    bool isValid(int x, int y, int n, int m, vector<vector<int>> &vis) {
        if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0)    return true;
        else                                                        return false;
    } 
    
    bool dfs(int x, int y, int n, int m, int mid, vector<vector<int>> &vis, vector<vector<int>> &mat) {
        
        // if cur index is equal to destination index
        if(x == n - 1 && y == m - 1)                  return true;
        
        vis[x][y] = 1;
        
        // Top, right, down, left
        // (-1, 0), (0, 1), (1, 0), (0, -1)
        
        for(int i=0; i<4; i++) {
            
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            
            if(isValid(x1, y1, n, m, vis) == true && abs(mat[x][y] - mat[x1][y1]) <= mid) {
                if(dfs(x1, y1, n, m, mid, vis, mat) == true)            return true;
            }
        }
        
        return false;
    }
        
    int minimumEffortPath(vector<vector<int>>& mat) {
    
        int ans = INT_MAX;
        
        int n = mat.size();
        int m = mat[0].size();
        
        int start = 0, end = INT_MAX, mid;
        
        while(start <= end) {
            
            // Here, mid is the maximum permissible difference
            int mid = start + (end - start) / 2;
            
            vector<vector<int>> vis(n, vector<int>(m, 0));
        
            if(dfs(0, 0, n, m, mid, vis, mat) == true) {
                ans = min(ans, mid);
                end = mid - 1;
            }
            
            else {
                start = mid + 1;
            }
            
        }
        
        return ans;
    }
    
};