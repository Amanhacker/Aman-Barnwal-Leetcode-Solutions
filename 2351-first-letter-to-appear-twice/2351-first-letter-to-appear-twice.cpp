class Solution {
public:
    
    char repeatedCharacter(string s) {
    
        char res = 'a';
        int n = s.length();
        
        unordered_map<char, int> mp;
       
        for(auto &x : s) {
            mp[x]++;            
            if(mp[x] == 2)                 return x;
        }   
        
        return res;
    }
    
};