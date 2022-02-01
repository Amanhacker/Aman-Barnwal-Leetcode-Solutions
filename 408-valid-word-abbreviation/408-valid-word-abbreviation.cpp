class Solution {
public:
    
    bool validWordAbbreviation(string word, string abbr) {
   
        // Check whether the string abbr matches the given word 
        
        int n = word.length();
        int i = 0, j = 0;
        
        for( ; i<abbr.length() && j < word.length(); ) {
            
            if(isdigit(abbr[i])) {
                
                if(abbr[i] == '0')                                         return false;
                
                int sum = 0;
                
                while(i < abbr.length() && isdigit(abbr[i])) {
                    sum = (sum * 10) + (int)(abbr[i] - '0');   
                    i++;
                }
                
                // Sum is the no.of characters
                j += sum;
                
                if(j > word.length())                                       return false;
            }
            
            // Current character is an alphabet
            else {
                
                if(abbr[i] != word[j])                                      return false;
                
                i++;
                j++;
            }
        }
        
        // If either of word or abbr is smaller in length
        if(i < abbr.length() || j < word.length())                          return false;
        
        return true;
        
    }
    
};