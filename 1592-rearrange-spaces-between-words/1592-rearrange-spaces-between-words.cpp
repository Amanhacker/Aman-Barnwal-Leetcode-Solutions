class Solution {
public:
    
    string reorderSpaces(string text) {
    
        string res = "";
        
        int noSpaces = 0;
        vector<string> words;
        
        string temp = "";
        
        for(int i=0; i<text.length(); ) {
            
            if(text[i] == ' ') {

                while(i < text.length() && text[i] == ' ') {
                    i++;
                    noSpaces++;
                }
                
                if(temp != "")                              words.push_back(temp);
                temp = "";
            }
            
            else {
                temp += text[i];
                i++;
            }
        }
        
        if(temp != "")                                      words.push_back(temp);
        
        int noWords = words.size();
        
        if(noWords == 1) {
            res += words[0];
            
            int c = noSpaces;
            while(c--)                                      res += ' ';
            
            return res;
        }
        
        int spacesExtra, spacesBetweenWords;
        spacesExtra = noSpaces % (noWords - 1);

        if(spacesExtra == 0) {
            // Then we can put these spaces between each word  
            spacesBetweenWords = noSpaces / (noWords - 1);
        } 
        
        // Else put extra spaces at the last
        
        for(int i=0; i<words.size(); i++) {
            
            res += words[i];

            if(i == words.size() - 1)                   break;

            int c = spacesBetweenWords;
            while(c--)                                  res += ' ';
        }
        
        if(spacesExtra > 0) {
            int c = spacesExtra;
            while(c--)                                  res += ' ';
        }
        
        return res;
    }
    
};