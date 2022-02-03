class Solution {
public:
    
    int maxDepth(string s) {
    
        int res = 0, cur = 0;
        int n = s.length();
        
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