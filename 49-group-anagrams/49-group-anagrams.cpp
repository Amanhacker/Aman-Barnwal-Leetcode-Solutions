class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& s) {
    
        vector<vector<string>> res;
        
        set<string> w;
        unordered_map<string, vector<string>> mp;
        
        for(auto &x : s) {
            
            string temp = x;
            sort(temp.begin(), temp.end());
            
            w.insert(temp);
            mp[temp].push_back(x);
        }
        
        
        for(auto &x : w) {
            res.push_back(mp[x]);    
        }
        
        return res;
    }
    
};