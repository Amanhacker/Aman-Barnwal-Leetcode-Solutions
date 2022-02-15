class Solution {
public:

    bool isValid(string word) {
        
        int n = word.length();
        int countHyphen = 0, countPunctuation = 0;
        
        for(int i=0; i<n; i++) {
            
            // No digit should be present
            if(isdigit(word[i]))                                                return false;
        
            // No punctuation marks at end of word
            if(word[i] == '!' || word[i] == '.' || word[i]== ',') {
                
                if(i != n-1)                                                    return false;
                
                countPunctuation++;
                if(countPunctuation >= 2)                                       return false;
            }
            
            // Hypen should be between two lowercase letter
            if(word[i] == '-') {
                
                countHyphen++;
                if(countHyphen >= 2)                                            return false;
                
                if(i == n-1 || i == 0)                                          return false;
                
                else if(i < n-1 && word[i+1] >= 'a' && word[i+1] <= 'z' && word[i-1] >= 'a' && word[i-1] <= 'z')        continue;
                
                else                                                            return false;
            }
        }
        
        return true;
    }
    
    int countValidWords(string sentence) {
    
        int res = 0;
        vector<string> v;
        
        stringstream ss(sentence);
        string word;
        
        while(ss >> word) {
            v.push_back(word);
        }
    
        
        for(auto &x : v) {
            if(isValid(x) == true)                                     res++;    
        }
        
        return res;
    }
    
};