class Solution {
public:
    
    bool isAnagram(string s, string t) {
    
        if(s == t)                      return true;
        
        map<int, int> mp;
        
        for(auto &x : s)                mp[x]++;
        for(auto &x : t)                mp[x]--;
        
        for(auto &x : mp) {
            if(x.second > 0 || x.second < 0)      return false;
        }
        
        return true;
    }
    
};