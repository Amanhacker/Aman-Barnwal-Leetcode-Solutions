class Solution {
public:
    
    bool isDecomposable(string s) {
    
        int n = s.length();
        
        // Value-equal string is a string where all characters are same
        
        // We need to decompose in such a way that there should be exactly 1 substring of length 2, and there can be any no.of substr of len 3
        
        int i = 0, j = 0;
        vector<int> v;              // It stores the length of equal-valued substrings
        
        while(i < n && j < n) {
            
            // Find the equal-value substring
            while(j + 1 < n && s[j] == s[j + 1]) {
                j++;
            }
            
            // Substring is from [i, j]
            int len = j - i + 1;
            
            if(len <= 1)                           return false;
            
            v.push_back(len);
            
            // Update i and j
            // Next substring starts from j + 1
            
            i = j + 1;
            j++;
        }
        
        bool f1 = false, f2 = false;
        
        if(v.size() == 1 && v[0] == 2)              return true;
        
        for(auto &x : v) {
            
            if(x == 2)                              f1 = true;
            
            // if len is odd
            else {
                
                // if x is exact multiple of 3
                if(x % 3 == 0)                      f2 = true;
                
                else if(x % 3 != 0) {
                    
                    // It must be multiple of lengths 2 and 3
                    x = x % 3; 
                    f2 = true;
                    
                    if(x == 2)                      f1 = true;
                    else                            return false;
                }
            }
        }        
        
        return (f1 && f2);
    }
    
};