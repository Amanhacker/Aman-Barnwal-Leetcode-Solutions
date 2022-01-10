class Solution {
public:
    
    bool areNumbersAscending(string s) {
    
        int n = s.length();
        vector<int> res;
        
        for(int i=0; i<n; i++) {
            
            if(isdigit(s[i]) == true) {
                // Push the digit into res
                
                string temp = "";
                
                while(s[i] != ' ' && i < n) {
                    temp += s[i];
                    i++;
                }
                
                res.push_back(stoi(temp));
            }
        }
        
        for(int i=1; i<res.size(); i++) {
            if(res[i-1] >= res[i])                          return false;
        }
        
        return true;
    }
    
};