class Solution {
public:
    
    bool areOccurrencesEqual(string s) {
    
        set<int> w;
        int n = s.length();
        
        unordered_map<char, int> u;
        
        for(auto &x : s)                        u[x]++;
        for(auto &x : u)                        w.insert(x.second);
        
        return (w.size() <= 1);
    }
    
};
