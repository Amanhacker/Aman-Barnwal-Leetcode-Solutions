class Solution {
public:
    
    static bool cmp(const string &s1, const string &s2) {
        
        // Get the substrings after the first white space character
        
        string aa = s1.substr(s1.find(' '));
        string bb = s2.substr(s2.find(' '));
        
		//if the substrings are equal, decide the order based on , else decide with respect to substrings
        return aa == bb ? s1 < s2 : aa < bb;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
    
        vector<string> res;
        vector<string> letterLogs, digitLogs;
        
        for(auto &x : logs) {
            
            string temp = x;
            
            // Put all letter logs in a letter log vector
            string word = "";
            int count = 0;
            
            bool isLetterLog = false, isDigitLog = false;
            
            for(int i=0; i<temp.length(); i++) {
                
                if(count >= 1) {
                    if(temp[i] != ' ') {
    
                        if(isalpha(temp[i]))                  isLetterLog = true;
                        if(isdigit(temp[i]))                  isDigitLog = true;
                        
                        break;
                    }
                }

                word += temp[i];    

                if(temp[i] == ' ') {
                    count++;
                    if(count == 1)                          word = "";
                }
                
            }
            
            if(isLetterLog == true)                         letterLogs.push_back(temp);
            else                                            digitLogs.push_back(temp);
        }
        
        
        sort(letterLogs.begin(), letterLogs.end(), cmp);
        
        for(auto &x : letterLogs)                           res.push_back(x);
        for(auto &x : digitLogs)                            res.push_back(x);
        
        return res;
    }
    
};