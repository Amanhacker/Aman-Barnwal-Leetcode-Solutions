class Solution {
public:
    
    string frequencySort(string s) {
    
        string res = "";
        
        if(s.length() == 0)                     return res;
        
        unordered_map<char, int> mp;
        for(auto &x : s)                        mp[x]++;
        
        vector<pair<int, char>> v;
        v.clear();
        
        for(auto &x : mp)                       v.push_back({x.second, x.first});
        
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        
        for(auto &x : v) {
            
            int freq = x.first;
            char ch = x.second;
                
            while(freq--)                   res += ch;
        }
        
        return res;
    }
    
};