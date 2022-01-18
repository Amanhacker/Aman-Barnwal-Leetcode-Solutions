class Solution {
public:
    
    // Using Optimized Memoization - MCM

    int findNoOfAttempts(int e, int n, vector<vector<int>> &dp){

        // Base Condition
        if(e == 1)              return n;
        if(n == 0 || n == 1)    return n;

        if(dp[e][n] != -1)      return dp[e][n];

        int mini = INT_MAX;

        for(int k=1; k<=n; k++){

            int l, r;

            if(dp[e-1][k-1] != -1)      l = dp[e-1][k-1];
            else                        l = findNoOfAttempts(e-1, k-1, dp);

            if(dp[e][n-k] != -1)        r = dp[e][n-k];
            else                        r = findNoOfAttempts(e, n-k, dp);

            int temp = 1 + max(l, r);
            //int temp = 1 + max(findNoOfAttempts(e-1, k-1), findNoOfAttempts(e, n-k)); // In simple memoization

            mini = min(mini, temp);
        }

        dp[e][n] = mini;
        return mini;
    }
    
    int twoEggDrop(int n) {
    
        if(n == 0)                      return 0;
        
        int e = 2;
        
        vector<vector<int>> dp;
        dp.resize(e + 1, vector<int>(n + 1, -1));
        
        return findNoOfAttempts(e, n, dp);
    }
    
};