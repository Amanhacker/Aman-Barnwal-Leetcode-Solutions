class Solution {
public:
  
    long long numberOfSubstrings(string s) {
    
        long long res = 0;
        int n = s.length();
        
        unordered_map<char, long long> mp;
        
        for(auto &x : s) {
            mp[x]++;
            res += mp[x];
        }           
        
        return res;
    }
    
};