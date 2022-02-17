class Solution {
public:
    
     
    int matrixScore(vector<vector<int>>& mat) {
    
        int res = 0;
        
        int n = mat.size();
        int m = mat[0].size();
        
        // Find the final matrix whose rows will give us the maximum possible score
        
        // Try to make the significant bit 1's
        
        // If MSB of any row is 0 then flip the entire row
        for(int i=0; i<n; i++) {
            
            if(mat[i][0] == 0) {
                // Flip the entire row
                for(int j=0; j<m; j++)                  mat[i][j] = 1 - mat[i][j];
            }
        }
        
        
        // If in any column, the no.of 0's > no.of 1's then flip the entire column
        
        for(int j=0; j<m; j++) {
            
            int zeroes = 0;
            int ones = 0;
            
            for(int i=0; i<n; i++) {
                if(mat[i][j] == 0)                              zeroes++;
                else                                            ones++;
            }
            
            if(zeroes > ones) {
                // Then flip the entire column
                for(int i=0; i<n; i++)                      mat[i][j] = 1 - mat[i][j];
            }
            
        }
        
        
        for(int i=0; i<n; i++) {
            
            int sum = 0, mul = 0;
            
            for(int j=m-1; j>=0; j--) {
                sum += mat[i][j] * pow(2, mul);
                mul++;
            }
            
            res += sum;
        }
        
        return res;
    }
    
};