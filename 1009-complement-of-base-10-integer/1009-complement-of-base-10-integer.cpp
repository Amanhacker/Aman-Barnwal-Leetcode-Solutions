class Solution {
public:
    
    int bitwiseComplement(int n) {
    
        int res = 0, mul = 1;
        
        if(n == 0)                                                      return 1;
        
        while(n > 0) {
            
            int rem = n % 2;
            rem ^= 1;
            
            res += rem * mul;
            mul *= 2;
            
            n = n / 2;
        }
        
        return res;
    }
    
};