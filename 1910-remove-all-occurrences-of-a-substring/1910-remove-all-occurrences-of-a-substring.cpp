class Solution {
public:
    
    string removeOccurrences(string s, string part) {
    
        int len = part.length();
        
        if(s.length() < part.length())                             return s;
        
        while(true) {
            
            auto ind = s.find(part);
            
            if(ind == string :: npos)                              return s;
            
            else {
                
                // ind is the starting index of leftmost occurence of string part in string s
                s.erase(ind, len);        
            }
        }
        
        return s;
    }
    
};