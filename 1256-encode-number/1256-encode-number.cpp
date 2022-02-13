class Solution {
public:
    
    
    string encode(int num) {
    
        string res = "";

        // Here, n is affecting the (2n + 1) and (2n + 2). 
        // Hence, we can at each step divide the number by (n - 1) / 2, to reach back to the old state.

        // If it is divisible by 2, we append 1. Else 0.
        
        while(num >= 2) {
            
            if(num % 2 == 1)                          res += "0";
            else                                      res += "1";
            
            num = (num - 1) / 2;
        }
        
        if(num == 2)                                  res += "1";
        if(num == 1)                                  res += "0";
        
        reverse(res.begin(), res.end());
        return res;
    }
    
};