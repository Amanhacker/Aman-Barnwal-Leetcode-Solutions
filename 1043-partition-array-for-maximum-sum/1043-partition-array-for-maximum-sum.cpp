class Solution {
public:
  
    int helperMaxSum(vector<int> &a, int n, int k, int pos, int &res, vector<int> &dp) {
        
        // Base Condition
        if(pos >= n)                                    return 0;
        if(pos < n && dp[pos] != -1)                    return dp[pos];
        
        int maxEle = 0;
        
        // For each position pos, increase your subarray size i from 0 to k - 1, tracking the max value maxEle so far. 
        // The sum of the subarray is maxEle * (i + 1).

        for(int i = 0; i < k && pos + i < n; i++) {
           
            maxEle = max(maxEle, a[pos + i]);
            
            int temp = ( maxEle * (i + 1) ) + helperMaxSum(a, n, k, pos + i + 1, res, dp);
            res = max(res, temp);
        }
        
        // Use memoisation to track the maximum sum for the position (dp).
        dp[pos] = res;
        return res;
    }
    
    int maxSumAfterPartitioning(vector<int>& a, int k) {
    
        int n = a.size();
        if(n == 0)                                      return 0;
        
        int pos = 0, res = 0;
        vector<int> dp(n + 1, -1);
        
        return helperMaxSum(a, n, k, pos, res, dp);
    }
    
};