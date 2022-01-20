class Solution {
public:
    
    string removeOccurrences(string s, string part) {
    
        int len = part.length();
        
        // if(s.length() < part.length())                             return s;
        
        while(true) {
            
            auto ind = s.find(part);
            
            if(ind == string :: npos)                              return s;
            else                                                   s.erase(ind, len);        
        }
        
        return s;
    }
    
};