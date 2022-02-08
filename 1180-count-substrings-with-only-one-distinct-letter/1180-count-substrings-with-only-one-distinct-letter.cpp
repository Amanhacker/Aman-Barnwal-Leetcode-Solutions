class Solution {
public:

    int countLetters(string s) {

        int n = s.length();
        int res = 0;                    // For every character
        
        // If a letter repeats n times, it forms n * (n + 1) / 2 valid substrings:
        
        // For all other substrings having length >= 2
        
        int i = 0, j = 0;
        
        for(int i=1, j=0; i<=n; i++) {
            
            if(i == n || s[i] != s[j]) {
                res += (i - j + 1) * (i - j) / 2;
                j = i;
            }
        }
        
        return res;
    }
    
};