class Solution {
public:

    int countLetters(string s) {

        int n = s.length();
        int res = 0;                    // For every character
        
        // If a letter repeats n times, it forms n * (n + 1) / 2 valid substrings:
        
        // For all other substrings having length >= 2
        
        int i = 0, j = 0;
        
        while(i < n && j < n) {
            
            // Divide the substring with only one distinct character of maximum length
            
            while(j + 1 < n && s[j] == s[j + 1]) {
                j++;
            }
            
            // Here, j is the index of new substring
            // So, length of substring is from [i, j]
            
            if(j < n) {
            
                int len = (j - i + 1);
                
                // string temp = s.substr(i, len);
                // cout << temp << " ";

                // No.of required substrings of length l = l * (l + 1) / 2;
                res += len * (len + 1) / 2;

                // Update i and j
                i = j + 1;
                j++;
            }
        }
         
        return res;
    }
    
};