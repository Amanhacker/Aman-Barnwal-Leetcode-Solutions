class Solution {
public:
    
    bool isNumber(string s) {
    
        int n = s.length();
        
        bool pointSeen = false;
        bool eSeen = false;
        bool noSeen = false;
        bool noAfterE = true;
        
        for(int i=0; i<n; i++) {
            
            if(s[i] >= '0' && s[i] <= '9') {
                noSeen = true;
                noAfterE = true;
            }
            
            else if(s[i] == '.') {
                
                if(eSeen == true || pointSeen == true)                      return false;
                
                pointSeen = true;
            }
            
            else if(s[i] == 'e' || s[i] == 'E') {
                
                if(eSeen == true || noSeen == false)                        return false;
                
                noAfterE = false;
                eSeen = true;
            }
            
            else if(s[i] == '-' || s[i] == '+') {
                
                if(i != 0 && s[i-1] != 'e')                                 return false;
            }
            
            else                                                            return false;
        }
        
        return noSeen && noAfterE;
    }
    
};