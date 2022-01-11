class Solution {
public:
    
    int maxScore(string s) {
    
        int res = 0;
        
        // Zeroes in left, and ones in right
        int n = s.length();
        int rightOnes = 0, leftZeroes = 0;
        
        for(auto &x: s) {
            if(x == '1')                            rightOnes++;
        }
        
        for(int i=0; i<n-1; i++) {
            
            if(s[i] == '0')                         leftZeroes++;
            else                                    rightOnes--;
            
            res = max(res, leftZeroes + rightOnes);
        }   

        return res;
    }
    
};