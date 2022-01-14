class Solution {
public:
    
    string gcdOfStrings(string s1, string s2) {
     
        string res = "";
        
        int n1 = s1.length();
        int n2 = s2.length();
        
        // Here, gcd exists
        if(s1 + s2 == s2 + s1) {
            int len = __gcd(n1, n2);
            res = s1.substr(0, len);
        }
        
        return res;
    }
    
};