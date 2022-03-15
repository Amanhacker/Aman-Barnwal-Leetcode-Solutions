class Solution {
public:
   
    int findLength(vector<int>& a1, vector<int>& a2) {
    
        int maxi = -1;
        
        int n = a1.size();
        int m = a2.size();
        
        // Find the max length of subarray that appears in both arrays
        
        // It is equivalent to Longest Common Substring
        
        vector<vector<int>> dp;
        dp.resize(n + 1, vector<int>(m + 1));

        for(int i=0; i<=n; i++)                 dp[i][0] = 0;
        for(int j=1; j<=m; j++)                 dp[0][j] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {

                if(a1[i-1] == a2[j-1])          dp[i][j] = 1 + dp[i-1][j-1];
                else                            dp[i][j] = 0;

                maxi = max(dp[i][j], maxi);
            }
        }

        return maxi;
    }
    
};