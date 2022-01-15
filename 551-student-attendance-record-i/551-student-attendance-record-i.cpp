class Solution {
public:
    
    bool checkRecord(string s) {
    
        int n = s.length();
        int abs = 0;
        
        for(int i=0; i<n; i++) {
            
            if(s[i] == 'A')                               abs++;
            
            else if(s[i] == 'L') {
                
                int late = 1;
                
                while(i + 1 < n && s[i] == s[i+1]) {
                    late++;
                    i++;
                }
                
                if(late >= 3)                             return false;
            }
        }
        
        if(abs >= 2)                                      return false;        
        
        return true;
    }
    
};