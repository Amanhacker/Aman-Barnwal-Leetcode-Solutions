class Solution {
public:
    
    bool isValid(int r, int c, int n, int m, vector<vector<char>> &board, char k) {
        
        
        // Same colum
        for(int i=0; i<n; i++) {
            if(board[i][c] == k)                    return false;
        }
        
        // Same row
        for(int c=0; c<m; c++) {
            if(board[r][c] == k)                    return false;
        }
        
        // For submatrices
        int smr = (r / 3) * 3;
        int smc = (c / 3) * 3;
        
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[smr + i][smc + j] == k)    return false;
            }
        }
        
        return true;
    }

    vector<vector<char>> _board;
    
    void solveSudokuHelper(int r, int c, int n, int m, vector<vector<char>> &board) {
        
        // If sol is found
        if(r == n) {
            
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
            _board = board;
            return;
        }
        
        else {
            
            int nr, nc;
            
            if(c == m-1) {
                nr = r + 1,
                nc = 0;
            }
            else {
                nr = r;
                nc = c + 1;
            }
            
            
            if(board[r][c] != '.') {
                solveSudokuHelper(nr, nc, n, m, board);
            }
            
            // Check whether k can be placed at (r, c)
            else {

                for(char k='1'; k<='9'; k++) {
                    
                    if(isValid(r, c, n, m, board, k) == true) {
                        
                        board[r][c] = k;
                        solveSudokuHelper(nr, nc, n, m, board);
                        board[r][c] = '.';
                    }
                }
            }
        }
        
        return;
    }
        
    void solveSudoku(vector<vector<char>> &board) {
    
        int n = board.size();
        int m = board[0].size();
        
        solveSudokuHelper(0, 0, n, m, board);
        board = _board;
        
        return;
    }
    
};