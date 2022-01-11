class Solution {
public:
    
    bool isPrefixString(string s, vector<string>& words) {
    
        int n = words.size();
        int ind = 0;
        
        int countLetter = 0;
        
        for(auto &x : words)                                                countLetter += x.length();
        
        if(s.length() > countLetter)                                        return false;
        
        for(int i=0; i<n; i++) {

            string temp = words[i];
            int k, j;
            
            if(ind >= s.length())                                           break;
            
            for(k=ind, j=0; k<ind + temp.length(); k++, j++) {
                if(temp[j] != s[k])                                         return false;
            }
            
            ind = k;
        }
        
        return true;
    }
    
};