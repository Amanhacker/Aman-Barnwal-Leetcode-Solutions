class Solution {
public:
    
    int romanToInt(string s) {
    
        int res = 0;
        int n = s.length();
        
        unordered_map<char, int> u;
        
        // IV - 4, IX - 9, XL - 40, XC - 90, CD - 400, CM - 900
        // V - 5, X - 10, L - 50, C - 100, D - 500, M - 1000 
        
        u['I'] = 1;
        u['V'] = 5;
        u['X'] = 10;
        u['L'] = 50;
        u['C'] = 100;
        u['D'] = 500;
        u['M'] = 1000;
        
        char temp;
        
        // s[i] temp
        
        for(int i=n-1; i>=0; i--) {
            
            if((temp == 'V' || temp == 'X') && s[i] == 'I')              res -= u[s[i]];
            else if((temp == 'L' || temp == 'C') && s[i] == 'X')         res -= u[s[i]];
            else if((temp == 'D' || temp == 'M') && s[i] == 'C')         res -= u[s[i]];
            else                                                         res += u[s[i]];
            
            temp = s[i];
        }
        
        return res;
    }
    
};