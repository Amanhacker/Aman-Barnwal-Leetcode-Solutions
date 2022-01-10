class Solution {
public:
    
    int canBeTypedWords(string text, string brokenLetters) {
    
        int ans;
        
        unordered_map<char, int> u;                 // contains broken letters
        for(auto &x : brokenLetters)                u[x]++;
        
        string temp = "";
        int noBrokenWords = 0;
        
        // Find the total no. of words in text
        int c = count(text.begin(), text.end(), ' ');
        int noWords = c + 1;
        
        for(int i=0; i<text.size(); i++) {
            
            temp += text[i];
            
            if(u[text[i]] >= 1) {
                
                // This means it contains one broken letter
                // Reach upto blank space
                
                while(text[i] != ' ' && i < text.size()) {
                    i++;
                }
                
                noBrokenWords++;
            }
        }
        
        ans = noWords - noBrokenWords;
        return ans;
    }
    
};