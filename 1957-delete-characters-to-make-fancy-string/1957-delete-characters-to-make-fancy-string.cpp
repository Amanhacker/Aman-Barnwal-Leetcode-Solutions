class Solution {
public:
    
    string makeFancyString(string s) {
    
        string res = "";
        int n = s.length();
        
        for(int i=0; i<n; i++) {
            
            // Check whether the substring having the same character starting at index i has 3 or more consecutive char or not
            int k = i;
            int count = 0;
            
            while(k + 1 < n && s[k] == s[k + 1])    k++;
            
            // Same char is from index i to k i.e [i, k]
            count = k - i + 1;
            
            if(count >= 3)                          res += s.substr(i, 2);
            else                                    res += s.substr(i, count);
                        
            i = k;
        }
        
        return res;
    }
    
};