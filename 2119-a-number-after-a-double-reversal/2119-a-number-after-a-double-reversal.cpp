class Solution {
public:
    
    bool isSameAfterReversals(int n) {
            
        if(n == 0)                                          return true;
        
        int lastDigit = n % 10;
    
        return (lastDigit != 0);
    }
    
};