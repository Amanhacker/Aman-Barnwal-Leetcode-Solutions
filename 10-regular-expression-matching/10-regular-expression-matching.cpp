class Solution {
public:
    
    bool isMatch(string s, string p) {
    
        return regex_match(s, regex(p));
    }
    
};