class Solution {
public:
   
    int countVowelSubstrings(string word) {
    
        int count = 0;
        int n = word.length();
        
        for(int i=0; i<n-4; i++) {
            for(int j=i+4; j<n; j++) {
                
                // Substr is from i to j i.e [i, j]
                string temp = word.substr(i, j - i + 1);
                
                bool isA = false, isE = false, isI = false, isO = false, isU = false, isConsonant = false;
                
                // Checks whether all 5 vowels present in the word
                for(auto &x : temp) {
                    if(x == 'a')                                    isA = true;
                    else if(x == 'e')                               isE = true;
                    else if(x == 'i')                               isI = true;
                    else if(x == 'o')                               isO = true;
                    else if(x == 'u')                               isU = true;
                    else                                            isConsonant = true;
                }
                
                if(isA && isE && isI && isO && isU && !isConsonant)                     count++;
            }
        }
        
        return count;
    }
    
};