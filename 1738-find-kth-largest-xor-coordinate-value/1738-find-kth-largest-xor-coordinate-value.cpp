class Solution {
public:
    
    int kthLargestValue(vector<vector<int>>& mat, int k) {
    
        int n = mat.size();
        int m = mat[0].size();
        
        // Finding value of all elements of matrix "mat"
        vector<vector<int>> dp;
        dp.resize(n, vector<int>(m));
        
        // Form max heap
        priority_queue<int> pq;
        
        int temp = 0;                                           // XORing with 0 will not change the value
        
        // Use Prefix sum method to fill XOR of matrix
        for(int i=0; i<n; i++) {
            
            // ith row
            temp = 0;
            
            for(int j=0; j<m; j++) {
                temp ^= mat[i][j];
                dp[i][j] = temp;
            }
        }
        
        // Now, XOR all the columns
        for(int j=0; j<m; j++) {
            
            // jth column
            temp = 0;
            
            for(int i=0; i<n; i++) {
                temp ^= dp[i][j];
                dp[i][j] = temp;
                
                pq.push(dp[i][j]);
            }
        }       
        
        if(pq.size() < k)                               return -1;
        
        int i = 0;
        
        while(i < k && pq.empty() == false) {
            
            i++;
            
            if(i == k)                                  break;
            pq.pop();
        }
        
        return pq.top();
    }
    
};