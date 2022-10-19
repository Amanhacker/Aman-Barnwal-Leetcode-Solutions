class Solution {
public:
    
    string longestPalindrome(string s) {
    
        string res = "";
        int n = s.length();
        
        int maxi = 0;
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // row - startIndex, column - endIndex
        
        // 1-length string
        for(int i=0; i<n; i++)                      dp[i][i] = 1;
        
        res = s[0];
        
        for(int i=n-1; i>=0; i--) {
            for(int j=i+1; j<n; j++) {
                
                // String from index [i, j]
                if(s[i] == s[j]) {
                    
                    if(j - i + 1 == 2 || dp[i + 1][j - 1] == 1) {

                        // If substring from [i+1, j-1] is a palindrome and if s[i] == s[j], then substring from [i, j] is also a palindrome

                        dp[i][j] = 1;
                        int len = j - i + 1;

                        if(len > maxi) {
                            maxi = len;
                            res = s.substr(i, len);
                        }
                    }
                }
            }
        }
        
        return res;
    }
    
};