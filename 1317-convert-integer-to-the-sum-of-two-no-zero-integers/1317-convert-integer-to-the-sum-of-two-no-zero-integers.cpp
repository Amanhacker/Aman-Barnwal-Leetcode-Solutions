class Solution {
public:

    bool isNonZero(int n) {
        
        while(n > 0) {
            
            int rem = n % 10;
            
            if(rem == 0)                                 return false;
            n = n / 10;
        }
        
        
        return true;
    }
    
    vector<int> getNoZeroIntegers(int n) {
    
        vector<int> res;
        
        int a, b;
        
        for(int i=1; i<=n; i++) {
            
            // Assume, a = i
            a = i;
            b = n - i;
            
            if(isNonZero(a) && isNonZero(b)) {
                res.push_back(a);
                res.push_back(b);
                
                return res;
            }
        }
        
        return res;
    }
    
};