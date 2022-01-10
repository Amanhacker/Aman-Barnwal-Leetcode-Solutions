class Solution {
public:
    
    bool checkString(string s) {
    
        int n = s.length();
        
        // Find the rightmost index of A, and leftmost index of B
        int maxIndexA = INT_MIN, minIndexB = INT_MAX;
        
        for(int i=0; i<n; i++) {
                        
            if(s[i] == 'a')                                 maxIndexA = max(i, maxIndexA);
            else                                            minIndexB = min(i, minIndexB);
        }
        
        return (maxIndexA < minIndexB);
    }
    
};