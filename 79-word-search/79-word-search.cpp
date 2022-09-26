class Solution {
public:
    
    // Top, right, down, left
    // (-1, 0), (0, 1), (1, 0), (0, -1)
    
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};

    bool isValid(int r, int c, int n, int m, vector<vector<int>> &vis) {
        if(r >= 0 && r < n && c >= 0 && c < m && vis[r][c] == 0)            return true;
        else                                                                return false;
    }
    
    bool existHelper(int x, int y, int n, int m, vector<vector<char>> &board, vector<vector<int>> &vis, string word, int ind) {
        
       if(board[x][y] == word[ind]) {
    
            vis[x][y] = 1;

            // Terminating Condition
            if(ind == word.length() - 1)                                       return true;

            for(int i=0; i<4; i++) {

                int x1 = x + dx[i];
                int y1 = y + dy[i];

                if(isValid(x1, y1, n, m, vis) == true) {
                    if(existHelper(x1, y1, n, m, board, vis, word, ind + 1) == true)              return true;
                }
            }
            
            vis[x][y] = 0;
            return false;
       }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));

        string s = "";
        bool flag = false;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                if(existHelper(i, j, n, m, board, vis, word, 0) == true)        return true;
            }
        }
        
        return false;
    }
    
};