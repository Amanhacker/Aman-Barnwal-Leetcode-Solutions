class Solution {
public:
    
    string longestPalindrome(string s) {
    
        string res = "";
        
        int maxLen = 1;
        int n = s.length();
        
        vector<vector<int>> dp;
        dp.resize(n, vector<int>(n, -1));
        
        // Every single char is a palindrome
        for(int i=0; i<n; i++)                      dp[i][i] = 1;
        
        res += s[0];
        
        for(int i=n-1; i>=0; i--) {
            for(int j=i+1; j<n; j++) {
                
                // Check whether the substring from index from [i, j] is a palindrome
                if(s[i] == s[j]) {
                
                    // If it is of 2 char or if the substring from [i+1, j-1] is a palindrome
                    if(j - i + 1 == 2 || dp[i + 1][j - 1] == 1) {
                       
                        // If substring from [i+1, j-1] is a palindrome and if s[i] == s[j], then substring from [i, j] is also a palindrome
                        dp[i][j] = 1;                  
                        int len = j - i + 1;

                        if(maxLen < len) {
                            maxLen = len;
                            res = s.substr(i, len);
                        }
                    }
                }
                
            }
        }
        
        return res;
    }
    
};