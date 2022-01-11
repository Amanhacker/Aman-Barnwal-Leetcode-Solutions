class Solution {
public:
   
    int countVowelSubstrings(string word) {
    
        int count = 0;
        int j = 0, k = 0, vow = 0;
        
        // j mark start of "all-vowel" substr, and i = current posn. The window between k - 1 and i is smallest window with all 5 vowels.
        // So, for each position i, we have k - j valid substrings
        
        unordered_map<char, int> u{{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
        
        for (int i=0; i<word.size(); i++) {
            
            if(u.count(word[i]) >= 1) {
                
                vow += ++u[word[i]] == 1;
                
                for ( ; vow == 5; k++)
                    vow -= --u[word[k]] == 0;
                
                count += k - j;
            }
            
            else {
            
                u['a'] = u['e'] = u['i'] = u['o'] = u['u'] = vow = 0;
                j = k = i + 1;
            }
        }
        
        return count;
    }
    
};