class Solution {
public:
    
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0]< b[0];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
    
        int res = 0;
       
        sort(pairs.begin(), pairs.end(), cmp);
        int n = pairs.size();
        
        // If a chain of length k ends at some pairs[i], and pairs[i][1] < pairs[j][0], we can extend this chain to a chain of length k+1.
        
        vector<int> dp(n, 1);
        // dp[i] be the length of the longest chain ending at pairs[i]. When i < j and pairs[i][1] < pairs[j][0]
        
        for(int j=1; j<n; j++) {
            for(int i=0; i<j; i++) {
                
                if(pairs[i][1] < pairs[j][0])                   dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        
        for(auto &x : dp)                                       res = max(res, x);
        return res;
    }
    
};