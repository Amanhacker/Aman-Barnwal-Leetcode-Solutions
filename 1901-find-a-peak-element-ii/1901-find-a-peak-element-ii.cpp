class Solution {
public:
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    
        vector<int> res;
    
        int n = mat.size();
        int m = mat[0].size();
        
        int startCol = 0, endCol = m - 1;
        
        while(startCol <= endCol) {
            
            int curCol = startCol + (endCol - startCol) / 2;
            
            // Find the maximum element in the column no curCol
            
            // maxRowIndex is the row no where the element is maximum in endCol index
            
            int maxRowIndex = 0;
            
            for(int i=0; i<n; i++) {
                
                if(mat[i][curCol] > mat[maxRowIndex][curCol]) {
                    // Update the row index
                    maxRowIndex = i;
                }
            }
            
            // Now, we ensured that the current column is greater than both top and bottom
            // But, we need to now check for left and right of current element
            
            // If left and right element are both smaller than current Element, then return co-ordinate
            if( (curCol == 0 || mat[maxRowIndex][curCol - 1] < mat[maxRowIndex][curCol]) && 
                (curCol == m - 1 || mat[maxRowIndex][curCol + 1] < mat[maxRowIndex][curCol]) ) {
                
                res.push_back(maxRowIndex);
                res.push_back(curCol);
                
                return res;
            }
            
            // Now, if left and right are not greater than current element

            // if left element is greater than current element
            else if(curCol - 1 >= 0 && mat[maxRowIndex][curCol - 1] > mat[maxRowIndex][curCol]) {
                endCol = curCol - 1;
            }
            
            // if right element is greater than current element
            else if(curCol + 1 < m && mat[maxRowIndex][curCol + 1] > mat[maxRowIndex][curCol]) {
                startCol = curCol + 1;
            }
        }
       
        return {-1, -1};
    }
    
};