class Solution {
public:

    // Possible movements are top, right, down, left
    // (-1, 0), (0, 1), (1, 0), (0, -1)
    
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    
    bool isValid(int x, int y, int n, int m, vector<vector<int>> &image, int val) {
        if(x >= 0 && x < n && y >= 0 && y < m && image[x][y] == val)                    return true;
        else                                                                            return false;
    }
    
    void bfs(int x, int y, int n, int m, vector<vector<int>> &image, vector<vector<int>> &res, int newColor) {
        
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        q.push({x, y});
        vis[x][y] = 1;
        
        res[x][y] = newColor;
        int val = image[x][y];
        
        while(q.empty() == false) {
            
            pair<int, int> temp = q.front();
            q.pop();
            
            for(int i=0; i<4; i++) {
                
                int wX = temp.first + dx[i];
                int wY = temp.second + dy[i];
                
                if(isValid(wX, wY, n, m, image, val) == true && vis[wX][wY] == 0) {
                    
                    res[wX][wY] = newColor;
                    
                    vis[wX][wY] = 1;
                    q.push({wX, wY});
                }
            }
        }
        
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
        vector<vector<int>> res;
        
        int n = image.size();
        int m = image[0].size();
        
        res.resize(n, vector<int>(m, 0));
        
        res = image;
        bfs(sr, sc, n, m, image, res, newColor);
        
        return res;
    }
    
};