class Solution {
public:
    
    bool canConstruct(string ransomNote, string magazine) {
    
        unordered_map<char, int> u;
        
        for(auto &x : magazine)                     u[x]++;
        
        for(auto &x : ransomNote) {
            if(u[x] >= 1)                           u[x]--;
            else                                    return false;
        }
        
        return true;
    }
    
};