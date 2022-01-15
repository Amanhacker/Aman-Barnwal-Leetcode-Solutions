class Solution {
public:
    
    bool repeatedSubstringPattern(string s) {
    
        int n = s.length();
        
        // On removing the first and the last characters, if there exists some pattern, we would still be able to find the original string somewhere in the middle, taking some characters from the first half and some from the second half.
        
        return (s + s).substr(1, 2*n-2).find(s) != -1;
    }
    
};