class Solution {
public:
    
    void nextPermutation(string &s, int n) {
        
        if(n == 0)                                          return;
        
        // Find the 1st number for which s[i] < s[i + 1]
        int i;
        
        for(i=n-2; i>=0; i--) {
            if(s[i] < s[i + 1])                             break;    
        }
        
        reverse(s.begin() + i + 1, s.end());
        
        if(i == -1)                                         return;
        
        auto it = upper_bound(s.begin() + i + 1, s.end(), s[i]);
        swap(s[i], *it);
        
        return;
    }
    
    int getMinSwaps(string str, int k) {
    
        int count = 0;
        int n = str.length();
        
        // Start from (n - 1) to 0, and if(s[i-1] < s[i]) then swap
        string s = str;
        
        while(k--) {
            
            string t = s;
            nextPermutation(s, n);
            
            if(t == s)                                       return 0;
        }

        string temp = s;
        
        while(true) {
            
            for(int i=n-1; i>=0; i--) {
                
                char ch = temp[i];
                
                // Find the index of ch in string str
                // No.of adjacent swaps taken to put ch at index i in temp from original string str = abs(it - i)
                
                int ind = i;
                
                for( ; ind>=0; ind--) {
                    if(str[ind] == ch)                                  break;
                }
                
                if(ind != i) {
                    
                    for(int j=ind; j<i; j++) {
                        
                        if(str[j] != str[j+1]) {
                        
                            swap(str[j], str[j + 1]); 

                            count++;
                            if(str == temp)                             return count;
                        }   
                    }
                }
            }
        }
        
        return count;
    }
    
};