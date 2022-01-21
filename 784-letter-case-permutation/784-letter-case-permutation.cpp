class Solution {
public:
    
    void findAllCasePermutations(int ind, string &s, int n, vector<string> &res) {
        
        // At one time, change one case to another
        
        for(int i=ind; i<n; i++) {
            
            if(!isdigit(s[i])) {
                if(islower(s[i]))                               s[i] = toupper(s[i]);
                else                                            s[i] = tolower(s[i]);
            }
            
            if(find(res.begin(), res.end(), s) == res.end())    res.push_back(s);
            
            findAllCasePermutations(i + 1, s, n, res);
            
            // Backtrack
            if(!isdigit(s[i])) {
                if(islower(s[i]))                               s[i] = toupper(s[i]);
                else                                            s[i] = tolower(s[i]);
            }
        }
        
        return;
    }
    
    vector<string> letterCasePermutation(string s) {
    
        vector<string> res;
        int n = s.length();
        
        res.push_back(s);
        
        // Using Recursion
        
        findAllCasePermutations(0, s, n, res);
        
        
        
        return res;
    }
    
};