class Solution {
public:
    
    int countSetBits(int n) {
        
        int c = 0;
        
        while(n > 0) {
            c += n % 2;
            n = n / 2;
        }
        
        return c;
    }
    
    bool isPrime(int n) {
        
        if(n <= 1)                                             return false;
        
        for(int i=2; i<=sqrt(n); i++) {
            if(n % i == 0)                                     return false;
        }
        
        return true;
    }
    
    int countPrimeSetBits(int left, int right) {
    
        int count = 0;
        
        for(int i=left; i<=right; i++) {
            int setBits = countSetBits(i);
            if(isPrime(setBits) == true)                        count++;
        }
        
        return count;
    }
    
};