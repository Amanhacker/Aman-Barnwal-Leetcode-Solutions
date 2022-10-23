class WordDictionary {
public:
    
    vector<string> v;

    WordDictionary() {
    
    }
    
    void addWord(string word) {
        v.push_back(word);
        return;
    }
    
    bool search(string word) {
       
        // Regex Expression
        
        int len = word.length();
        
        for(auto &str : v) {
            
            if(str.length() == len) {
                
                bool flag = true;

                for(int i=0; i<len; i++) {
                
                    if(word[i] != '.') {
                        
                        if(str[i] != word[i]) {
                            flag = false;
                            i = len;
                        }
                    }
                }
                
                if(flag == true)                        return true;
            }
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */