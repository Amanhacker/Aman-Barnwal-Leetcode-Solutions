class Solution {
public:
    
    int maxLengthBetweenEqualCharacters(string s) {
    
        int ans = -1;
        int n = s.length();
        
        for(int i=0; i<n; i++) {
            
            char ch = s[i];
            
            for(int k=n-1; k>=i+1; k--) {
                
                if(ch == s[k]) {
                    ans = max(ans, k-1 - (i+1) + 1);
                    break;
                }
            }
            
        }
        
        
        return ans;
    }
    
};