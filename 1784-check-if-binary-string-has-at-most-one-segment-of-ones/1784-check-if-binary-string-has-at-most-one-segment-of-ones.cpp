class Solution {
public:
    
    bool checkOnesSegment(string s) {
    
        int n = s.length();
        bool isZero = false, isOne = false;

        if(s[0] == '0')                                                         isZero = true;
        else                                                                    isOne = true;
        
        for(int i=1; i<n; i++) {
            
            if(isZero == true && isOne == true && s[i] == '1')                  return false;
            
            if(s[i] == '0')                                                     isZero = true;
            else                                                                isOne = true;
        }
        
        return true;
    }
    
};
