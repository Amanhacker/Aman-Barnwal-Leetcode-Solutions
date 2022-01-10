class Solution {
public:
    
    int arraySign(vector<int>& v) {
    
        int noNegative = 0, noZero = 0;
        
        for(auto &x : v) {
            if(x == 0)                                  noZero++;
            else if(x < 0)                              noNegative++;
        }
        
        if(noZero >= 1)                                 return 0;
        
        else if(noNegative >= 1) {
            if(noNegative % 2 == 0)                     return 1;
            else                                        return -1;
        }
        
        return 1;
    }
    
};