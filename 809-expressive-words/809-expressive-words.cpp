class Solution {
public:

    // Check whether string w is the stretchy string of string s
    bool isCheck(string s, string w) {
        
        int n = s.length();
        int m = w.length();
        
        int j = 0;
        
        for(int i=0; i<n; i++) {
            
            if(j < m && s[i] == w[j])                                       j++;
                
            else if(i >= 2 && s[i-2] == s[i-1] && s[i-1] == s[i])           continue;
            else if(i >= 1 && s[i-1] == s[i] && s[i] == s[i+1])             continue;
            
            else                                                            return false;
        }
        
        return (j == m);
    }
    
    int expressiveWords(string s, vector<string>& words) {
    
        int count = 0;
        
        for(auto &x : words) {
            if(isCheck(s, x) == true)                                       count++;
        }
        
        return count;
    }
    
};