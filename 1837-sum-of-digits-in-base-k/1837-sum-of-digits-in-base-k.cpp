class Solution {
public:
    
    int sumBase(int n, int k) {
    
        int sum = 0;
        vector<int> digits;
        
        // First, convert the number n from base 10 to base k
        while(n > 0) {
            
            int dig = n % k;
            digits.push_back(dig);
            
            n =  n / k;
        }        
        
        for(auto &x : digits)               sum += x;
        
        return sum;
    }
    
};