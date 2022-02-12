class Solution {
public:
    
    int minFlips(string target) {
    
        int res = 0;
        int n = target.length();
        
        // We need to make target from temp with minimum no.of flips
        
        int state = 0;
        
        for(int i=0; i<n; i++) {
            
            if(target[i] - '0' != state) {
                state = target[i] - '0';
                res++;
            }
            
        }
        
        return res;
    }
    
};