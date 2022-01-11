class Solution {
public:
    
    int isPrefixOfWord(string s, string searchWord) {
    
        int n = s.length();
        int ind = 1;
        
        for(int i=0; i<n; i++) {
            
            string word = "";
            int start = i;
            
            while(s[i] != ' ' && i < n) {
                word += s[i];
                i++;
            }

            auto it = word.find(searchWord);
            if(it != string::npos) {
                if(it == 0)                                          return ind;
            }             
            
            ind++;
        }
        
        return -1;
    }
    
};