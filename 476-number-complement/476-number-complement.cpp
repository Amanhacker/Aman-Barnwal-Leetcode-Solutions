class Solution {
public:
    
    int findComplement(int n) {
        
        unsigned mask = ~0;
        while(mask & n)                                 mask = mask << 1;
        
        return ~n ^ mask;
    }
    
};