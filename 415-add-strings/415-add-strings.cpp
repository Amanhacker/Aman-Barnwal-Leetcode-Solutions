class Solution {
public:
    
    string addStrings(string s1, string s2) {
    
        string res = "";
        
        int n1 = s1.length();
        int n2 = s2.length();
        
        if(s1 == "0")                                   return s2;
        if(s2 == "0")                                   return s1;
        
        int carry = 0;
        int i = n1 - 1, j = n2 - 1;
        
        for( ; i >= 0 && j >= 0; i--, j--) {
            
            int temp = (int)(s1[i] - '0') + (int)(s2[j] - '0') + carry;
            
            if(temp <= 9) {
                res += to_string(temp);                
                carry = 0;
            }   
            
            else {
                res += to_string(temp % 10);
                carry = temp / 10;
            }
        }
        
        while(i >= 0) {
            
            int temp = (int)(s1[i] - '0') + carry;
            
            if(temp <= 9) {
                res += to_string(temp);                
                carry = 0;
            }   
            
            else {
                res += to_string(temp % 10);
                carry = temp / 10;
            }
            
            i--;
        }
        
        while(j >= 0) {
            
            int temp = (int)(s2[j] - '0') + carry;
            
            if(temp <= 9) {
                res += to_string(temp);
                carry = 0;
            }   
            
            else {
                res += to_string(temp % 10);
                carry = temp / 10;
            }
            
            j--;
        }
        
        if(carry != 0)                                  res += to_string(carry);
        reverse(res.begin(), res.end());
        
        return res;
    }
    
};