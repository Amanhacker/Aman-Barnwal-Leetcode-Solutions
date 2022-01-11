class Solution {
public:
    
    int longestPalindrome(string s) {
    
        int res = 0;
        int n = s.length();
        
        unordered_map<int, int> u;
        
        for(auto &x : s)                    u[x]++;
        
        bool flag = false;
        
        for(auto &x : u) {
            
            if(x.second % 2 == 0)           res += x.second;
            
            else {
                flag = true;
                if(x.second >= 3)           res += (x.second - 1);
            }   
        }
        
        if(flag == true)                    res++;        
        return res;
    }
    
};