class Solution {
public:
    
    string longestCommonPrefix(vector<string> &s) {
    
        string res = "";
        
        int n = s.size();
        if(n == 0)                                         return res;
        
        sort(s.begin(), s.end());
        
        string first = s[0];
        string last = s[n-1];
        
        int c = 0;
        
        while(c < first.length()) {
            
            if(first[c] == last[c])                         c++;
            else                                            break;
        }
        
        if(c != 0)                                          res = first.substr(0, c);
        
        return res;
    }
    
};