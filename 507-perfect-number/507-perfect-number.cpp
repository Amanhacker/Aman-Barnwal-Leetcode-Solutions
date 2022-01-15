class Solution {
public:
    
    bool checkPerfectNumber(int num) {
    
        int sum = 1;
        
        if(num == 1)                                return false;
        
        // Find all the divisors of numbers
        for(int i=2; i<=num/2; i++) {
            if(num % i == 0)                        sum += i;
        }
                
        return (sum == num);
    }
    
};