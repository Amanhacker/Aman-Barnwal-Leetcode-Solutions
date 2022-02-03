class Solution {
public:
    
    int maxDepth(string s) {
    
        int res = 0, cur = 0;
        int n = s.length();
        
        // Ignore digits and signs, only count the current open parentheses cur.
        // The depth equals to the maximum open parentheses.
        
        for(int i=0; i<n; i++) {
            
            if(s[i] == '(') {
                cur++;
                res = max(res, cur);                
            }
            
            else if(s[i] == ')') {
                cur--;
            }
        }
        
        return res;
    }
    
};