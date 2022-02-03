class Solution {
public:

    vector<string> helperWordBreak(string &s, int ind, int n, unordered_set<string> &word, unordered_map<int, vector<string>> &u) {
        
        vector<string> res;
        
        // Base Condition
        if(ind == n) {
            res.push_back(" ");
            return res;
        }
        
        if(u.count(ind))                                   return u[ind];
        
        string temp = "";
        vector<string> sub;
        
        for(int i=ind; i<n; i++) {
            
            temp += s[i];
            
            // If set has index, where word didn't break
            if(word.count(temp)) {
                
                 // Creating the partition at (i + 1)
                
                 // Get Recurrence for rest of the string
                 sub = helperWordBreak(s, i + 1, n, word, u);
            
                 for(auto x : sub) {

                      if(x == " ")                               res.push_back(temp);
                      else                                       res.push_back(temp + " " + x);
                 }
            }
        }
        
        u[ind] = res;
        return res;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    
        int n = s.length();
        
        unordered_set<string> word;
        unordered_map<int, vector<string>> w;
        
        for(auto &x : wordDict)                             word.insert(x);
        
        return helperWordBreak(s, 0, n, word, w);
    }
    
};