class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
        vector<vector<string>> res;
        map<string, vector<string>> mp;
        
        int n = strs.size();
        
        if(n == 0)                                                      return res;
        
        for(auto &x : strs) {
            
            string temp = x;
            sort(temp.begin(), temp.end());
            
            mp[temp].push_back(x);
        }
        
        for(auto &x : mp)                                               res.push_back(x.second);
        return res;
    }
    
};