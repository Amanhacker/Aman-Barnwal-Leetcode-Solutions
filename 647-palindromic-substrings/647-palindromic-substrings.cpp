class Solution {
public:

    void extendPalindrome(string s, int left, int right, int &count) {
        
        int n = s.length();

        if(left < 0 || right >= n)                  return;
        
        while(left >=0 && right < n && s[left] == s[right]) {
            
            left--;
            right++;
            
            count++;
        }        
        
        return;
    }
    
    int countSubstrings(string s) {
    
        int count = 0;
        int n = s.length();
        
        if(n == 0)                                         return 0;
        
        for(int i=0; i<n; i++) {
            
            // Considering i as the mid point
            
            extendPalindrome(s, i, i, count);              // Odd length
            extendPalindrome(s, i, i + 1, count);          // Even length
        }
        
        return count;        
    }
    
};