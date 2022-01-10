class Solution {
public:
    
    int findComplement(int n) {
        
        string res = "";
        
        while(n > 0) {
            res += to_string(n % 2);
            n = n / 2;
        }
        
        for(int i=0; i<res.size(); i++) {
            if(res[i] == '0')                           res[i] = '1';
            else                                        res[i] = '0';
        }
        
        // Here, res contains binary in reverse order
        int ans = 0, mul = 1;;
        
        
        for(int i=0; i<res.size(); i++) {
            ans += ((int)(res[i]) - '0') * mul;
            if(mul < INT_MAX / 2)                             mul *= 2;
        }
        
        return ans;
    }
    
};