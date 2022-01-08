class Solution {
public:
   
    int findMaxDiff(int n, vector<int> &piles, int i, int m, vector<vector<int>> &dp) {
        
        // Base Condition
        if(i == n)                                          return 0;
        if(dp[i][m] != -1)                                  return dp[i][m];
        
        // Take the first x stones starting from i, where x lies in range [1, 2*m]
        // x = j - i + 1;
        
        int ans = INT_MIN, sumTemp = 0;
        
        // Starting from j stone and reach upto j + x - 1 stones
        for(int j=i; j < n && j - i + 1 <= 2*m; j++) {
            
            sumTemp += piles[j];
            
            // Update m to max(m, x)
            ans = max(ans, sumTemp - findMaxDiff(n, piles, j + 1, max(m, j - i + 1), dp));
        }
        
        dp[i][m] = ans;
        return ans;
    }
    
    int stoneGameII(vector<int>& piles) {
    
        int n = piles.size();
        
        // Alice always starts first
        vector<vector<int>> dp;
        dp.resize(n + 1, vector<int>(2*n + 1, -1));
        
        // Find the sum of all the elements of piles
        int sum = accumulate(piles.begin(), piles.end(), 0);
        
        // Let Alice collects total a amount, and Bob collects total b amount, and maxDiff between them is maxDiff
        // i.e 1). a + b = sum, and 2). maxDiff = a - b, so a = (sum + maxDiff) / 2;
        
        // Calculate the net max difference possible between the stones collected by Alice and Bob, considering Alice always collect more stones than Bob
        
        int maxDiff = findMaxDiff(n, piles, 0, 1, dp);
        int res = (sum + maxDiff) / 2;
        
        return res;
    }
    
};