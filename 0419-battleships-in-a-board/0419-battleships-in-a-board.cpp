class Solution {
public:

    // Top, right, down, left
    // (-1, 0), (0, 1), (1, 0), (0, -1)
    
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    
    void dfs(int x, int y, int n, int m, vector<vector<char>> &board) {
        
        if(x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'X')            return;    
        
        board[x][y] = '.';
        
        for(int i=0; i<4; i++) {
            
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            
            dfs(x1, y1, n, m, board);
        }
        
        return;
    }
    
    int countBattleships(vector<vector<char>>& board) {
    
        int count = 0;
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
            
                if(board[i][j] == 'X') {
                   dfs(i, j, n, m, board);
                   count++;
                }
            }
        }
        
        return count;
    }
    
};