class Solution {
public:
    
    bool canPermutePalindrome(string s) {
    
        unordered_map<char, int> u;
        int count = 0;
        
        for(auto &x : s)                            u[x]++;
        
        // If more than odd occurence of number exists, then return false
        
        for(auto &x : u) {
            if(x.second % 2 == 1)                   count++;
            if(count >= 2)                          return false;
        }
        
        return true;
    }
    
};