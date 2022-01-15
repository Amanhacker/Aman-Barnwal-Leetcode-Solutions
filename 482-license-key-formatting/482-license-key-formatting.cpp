class Solution {
public:
    
    string licenseKeyFormatting(string s, int k) {
    
        string res = "";
        
        int n = s.length();
        
        int noDashes = count(s.begin(), s.end(), '-');
        int noLetters = n - noDashes;
        
        if(noLetters == 0)                                      return "";
        if(n < k)                                               return s;
        
        string temp = "";
        
        for(auto &x : s) {
            if(x != '-')                                        temp += toupper(x);
        }
        
        int noGroups, firstGroupNo = 0;
        
        // First group is having no.os letters < k
        firstGroupNo = noLetters % k;
        
        noGroups = noLetters / k;
        int i = 0;
        
        if(firstGroupNo > 0) {
            
            int c = firstGroupNo;
            res += temp.substr(i, c);
            
            i = c;
            
            res += '-';
        }
        
        while(i < temp.size()) {
            
            if(i + k - 1 < temp.size())                        res += temp.substr(i, k);
            
            if(i + k == temp.size())                           break;
            
            res += '-';
            i = i + k;
        }
        
        return res;
    }
    
};