class Solution {
public:
    
    static bool cmp(const string &a, const string &b) {
        
        string word1 = "", word2 = "";
        int ind1, ind2;
        
        for(int i=0; i<a.length(); i++) {
            if(a[i] == ' ') {
                ind1 = i;
                break;
            }
        }
        
        for(int j=0; j<b.length(); j++) {
            if(b[j] == ' ') {
                ind2 = j;
                break;
            }
        }
        
        string log1 = a.substr(ind1 + 1, a.length() - ind1);
        string log2 = b.substr(ind2 + 1, b.length() - ind2);
        
        // Identifier is from [0, ind - 1], and logs are from [ind + 1, len - ind - 1 + 1]
        
        if(log1 != log2)                                    return log1  < log2;
        else                                                return a < b;
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