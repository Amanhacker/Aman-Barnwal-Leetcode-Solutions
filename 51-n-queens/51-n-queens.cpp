class Solution {
public:
    
    vector<vector<string>> res;
    vector<string> temp;
    
    bool isValid(int r, int c, int n, vector<vector<char>> &board) {
        
        // Same column
        for(int i=0; i<n; i++) {
            if(board[i][c] == 'Q')                     return false;
        }
        
        // Upper left diagonal
        for(int i=r-1, j=c-1; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q')                     return false;
        }
        
        // Upper right diagonal
        for(int i=r-1, j=c+1; i>=0 && j<n; i--, j++) {
            if(board[i][j] == 'Q')                     return false;
        }
        
        return true;
    }
    
    void NQueen(int r, int n, vector<vector<char>> &board) {
        
        // if sol is found
        if(r == n - 1) {
            
            temp.clear();
            
            for(int i=0; i<n; i++) {
                
                string t = "";
                
                for(int j=0; j<n; j++)                     t += board[i][j];
                temp.push_back(t);
            }
            
            res.push_back(temp);
            temp.clear();
        }
        
        else {
            
            for(int col = 0; col < n; col++) {
                
                int r1 = r + 1;
                
                if(isValid(r1, col, n, board) == true) {
                    
                    board[r1][col] = 'Q';
                    NQueen(r1, n, board);
                    board[r1][col] = '.';
                }
            }
        }
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
    
        vector<vector<char>> board(n, vector<char>(n, '.'));
        NQueen(-1, n, board);
        
        return res;
    }
    
};