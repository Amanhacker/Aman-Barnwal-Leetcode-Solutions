class Solution {
public:
    
    bool areSentencesSimilar(vector<string>& s1, vector<string>& s2, vector<vector<string>>& simPairs) {
    
        map<string, vector<string>> u;
        
        for(auto &x : simPairs) {
            u[x[0]].push_back(x[1]);
            u[x[1]].push_back(x[0]);
        }
        
        if(s1.size() != s2.size())                                                        return false;
        
        else {
            
            if(s1 == s2)                                                                  return true;
            
            for(int i=0; i<s1.size(); i++) {
                
                vector<string> t1 = u[s1[i]];
                vector<string> t2 = u[s2[i]];
                
                auto it1 = find(t1.begin(), t1.end(), s2[i]);
                auto it2 = find(t2.begin(), t2.end(), s1[i]);
                
                if(s1[i] != s2[i] && it1 == t1.end() && it2 == t2.end())                  return false;
            }
        }
            
        return true;
    }
    
};