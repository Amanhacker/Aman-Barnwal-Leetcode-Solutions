class Solution {
public:
    
    bool isPalindrome(string s) {
        
        int n = s.length();
        int i = 0, j = n - 1;
        
        while(i < j) {
           
            if(s[i] != s[j])                                    return false;
            else {
                i++;
                j--;
            }
        }
        
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
    
        int n = words.size();
        
        for(auto &x : words) {
            if(isPalindrome(x) == true)                             return x;
        }
        
        return "";
    }
    
};