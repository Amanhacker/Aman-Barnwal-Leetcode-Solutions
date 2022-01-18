class Solution {
public:

    int numSplits(string s) {
        
        int res = 0;
        int n = s.length();
      
        vector<int> left(26, 0), right(26, 0);          // Count of freq of each character
        int dLeft = 0, dRight = 0;                      // No. of distinct character

        // We first count each character (r[ch]), and no. of distinct characters (dRight).
        // These are initial numbers for our right substring (thus, indicated as r).
        
        for(auto &ch : s) {
            
            right[ch - 'a']++;
            if(right[ch - 'a'] == 1)                    dRight++; 
        }
        
        // As we move our split point from left to right, we "move" the current character to the left substring, 
        // and update count and distinct characters in left and right substrings.
    
        for(auto &ch : s) {
            
            left[ch - 'a']++;
            if(left[ch - 'a'] == 1)                     dLeft++;
            
            right[ch - 'a']--;
            if(right[ch - 'a'] == 0)                    dRight--;
            
            // If the number of distict characters is equal, we increment the result.
            if(dLeft == dRight)                         res++;
        }
        
        return res;
    }
    
};