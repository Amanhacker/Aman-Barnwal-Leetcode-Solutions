class Solution {
public:
  
    int numSplits(string s) {
        
        int res = 0;
        int n = s.length();
        
        vector<int> left(26, 0), right(26, 0);          // Count of freq of each character
        int dLeft = 0, dRight = 0;

        for(auto &ch : s) {
            
            right[ch - 'a']++;
            if(right[ch - 'a'] == 1)                    dRight++; 
        }
        
        for(auto &ch : s) {
            
            left[ch - 'a']++;
            if(left[ch - 'a'] == 1)                     dLeft++;
            
            right[ch - 'a']--;
            if(right[ch - 'a'] == 0)                    dRight--;
            
            if(dLeft == dRight)                         res++;
        }
        
        return res;
    }
    
};