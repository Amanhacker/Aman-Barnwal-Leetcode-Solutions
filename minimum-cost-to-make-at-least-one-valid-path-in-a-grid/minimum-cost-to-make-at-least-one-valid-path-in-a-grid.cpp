class Solution {
public:
    
    // Using BFS on 2D Grid
    
    // All 4 directions : right, left, down, up
    // (0, 1), (0, -1), (1, 0), (-1, 0)
    
    int dx[4] = {0,  0, 1, -1};
    int dy[4] = {1, -1, 0,  0};
    
    bool isValid(int x, int y, int n, int m) {
        if(x >= 0 && x < n && y >= 0 && y < m)                                  return true;
        return false;
    }
    
    void bfs(int x, int y, int n, int m, vector<vector<int>> &dist, vector<vector<int>> &grid) {
        
        queue<pair<int, int>> q;
        
        q.push({x, y});
        
        while(q.empty() == false) {
            
            pair<int, int> temp = q.front();
            q.pop();
            
            int x1 = temp.first;
            int y1 = temp.second;
            
            for(int i=0; i<4; i++) {
                
                int wX = temp.first + dx[i];
                int wY = temp.second + dy[i];
                
                if(isValid(wX, wY, n, m) == true) {
                   
                    if(i + 1 == grid[x1][y1] && dist[x1][y1] < dist[wX][wY]) {
                        dist[wX][wY] = dist[x1][y1];
                        q.push({wX, wY});
                    }
                    
                    else if(dist[x1][y1] + 1 < dist[wX][wY]) {
                        dist[wX][wY] = dist[x1][y1] + 1;
                        q.push({wX, wY});
                    }
                }
            }
        }
        
        return;
    }
    
    int minCost(vector<vector<int>>& grid) {
    
        int n = grid.size();
        int m = grid[0].size();
        
        if(n == 0)                                                  return 0;
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        dist[0][0] = 0;
        
        bfs(0, 0, n, m, dist, grid);
        
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 cout << dist[i][j] << " ";
//             }
//             cout << endl;
//         }
        
//         cout << endl;
        
        return dist[n-1][m-1];
    }
    
};