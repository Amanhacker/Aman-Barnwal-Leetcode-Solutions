class Solution {
public:
    
    int findComplement(int n) {
        
        // Basic idea is to find the smallest power of 2 that is larger than num, and output the difference between powerof2s and num .
        
        long powerof2s = 2, temp = n;
        
        while(temp >> 1) {
            temp >>= 1;
            powerof2s <<= 1;
        }
        
        return (powerof2s - n - 1);
    }
    
};