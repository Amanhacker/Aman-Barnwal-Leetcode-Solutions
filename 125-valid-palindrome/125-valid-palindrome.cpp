class Solution {
public:
    
    bool isPalindrome(string s) {
    
        string res = "";
        
        for(auto &ch : s) {
            if(isalpha(ch) || isdigit(ch)) {
                res += tolower(ch);
            }
        }
        
        string temp = res;
        reverse(res.begin(), res.end());
        
        return (temp == res);
    }
    
};