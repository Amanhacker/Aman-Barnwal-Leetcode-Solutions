class Solution {
public:
    
    int maximum69Number (int n) {
    
        string s = to_string(n);
        int siz = s.length();
        
        bool flag = false;
        
        int ind;
        
        for(int i=0; i<siz; i++) {
          
            if(s[i] == '6') {
                
                s[i] = '9';
                ind = i;
                
                flag = true;
                break;
            }
        }
        
        if(flag == false)                                       return n;
        
        // ind is the index which changes from 6 to 9
        int noZeroes = s.length() - ind - 1;
        
        // Add 3 * noZeroes to n
        int mul = 3;
        
        while(noZeroes--)                                        mul *= 10;
        
        return n + mul;
    }
    
};