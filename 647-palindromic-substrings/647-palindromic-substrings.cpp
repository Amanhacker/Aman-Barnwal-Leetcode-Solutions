class Solution {
public:

    bool isPalindrome(string s) {
        
        int n = s.length();
        
        for(int i=0, j=n-1; i<=j; i++, j--) {
            if(s[i] != s[j])                                return false;
        }
        
        return true;
    }
    
    int countSubstrings(string s) {
    
        int count = 0;
        int n = s.length();
        
        // Generate all substring
        
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                
                // Substring is from index [i, j]
                int len = j - i + 1;
                string temp = s.substr(i, len);
                
                if(isPalindrome(temp) == true)                  count++;
            }
        }
        
        return count;        
    }
    
};