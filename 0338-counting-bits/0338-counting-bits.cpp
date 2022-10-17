class Solution {
public:
    
    vector<int> countBits(int n) {
    
        vector<int> res;
        
        if(n == 0)                          return {0};
        if(n == 1)                          return {0, 1};
        
        res.push_back(0);
        res.push_back(1);
        
        for(int i=2; i<=n; i++) {
            
            // Binary Representation of number i
            // No.of 1's bits in number i
            
            int num = i, count = 0;
            
            while(num > 0) {
                count += (num % 2);
                num = num / 2;
            }
            
            res.push_back(count);
        }
        
        return res;
    }
    
};