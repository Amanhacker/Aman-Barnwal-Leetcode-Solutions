class Solution {
public:
    
    vector<int> selfDividingNumbers(int left, int right) {
    
        vector<int> res;
        
        for(int i=left; i<=right; i++) {
            
            int n = i;
            
            // n should not contain zero
            // n should be divisible by all its digits
            
            if(n == 0)                                                      continue;
            
            if(n >= 1 && n <= 9)                                            res.push_back(i);
            else {
                
                bool hasZero = false, isDivisible = true;
                bool f = true;
                
                while(n > 0 && f == true) {
                
                    int dig = n % 10;

                    if(dig == 0) {
                        hasZero = true;
                        f = false;
                    }

                    else if(i % dig != 0) {
                        isDivisible = false;
                        f = false;
                    }

                    n = n / 10;
                }

                if(hasZero == false && isDivisible == true)                         res.push_back(i);
            }
            
        }
        
        return res;
    }
    
};