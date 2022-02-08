class Solution {
public:
    
    bool validWordSquare(vector<string>& words) {
    
        int n = words.size();
        
        for(int i=0; i<n; i++) {
            
            string temp = "";
        
            if(words[i].size() > n)                                     return false;
            
            for(int j=0; j<words[i].length(); j++)                      temp += words[j][i];
            
            if(words[i] != temp)                                        return false;
        }
       
        return true;
    }
    
};