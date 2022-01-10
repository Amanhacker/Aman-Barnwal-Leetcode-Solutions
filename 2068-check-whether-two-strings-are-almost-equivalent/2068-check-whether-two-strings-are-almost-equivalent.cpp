class Solution {
public:
    
    bool checkAlmostEquivalent(string word1, string word2) {
    
        unordered_map<char, int> u1, u2;
        
        for(auto &x : word1)                        u1[x]++;
        for(auto &x : word2)                        u2[x]++;
        
        for(int i=0; i<26; i++) {
            
            char ch = (char)(i + 97);
            
            if( (u1[ch] > 0 || u2[ch] > 0) && abs(u1[ch] - u2[ch]) > 3)                         return false;
        }
        
        return true;
    }
    
};