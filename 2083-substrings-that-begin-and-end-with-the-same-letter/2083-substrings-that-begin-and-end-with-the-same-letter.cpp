class Solution {
public:
  
    long long numberOfSubstrings(string s) {
    
        long long res = 0;
        int n = s.length();
        
        // For all substrings of length 1
        res += n;
        
        // For remaining substrings of length >= 2
        unordered_map<char, long long> mp;
        
        for(auto &x : s)                            mp[x]++;
        for(auto &x : mp)                           res += (x.second) * (x.second - 1) / 2;
        
        return res;
    }
    
};