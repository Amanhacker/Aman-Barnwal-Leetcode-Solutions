class Solution {
public:
    
    int minSteps(string s, string t) {
    
        int count = 0;
        
        int n = s.length();
        int m = t.length();
        
        unordered_map<char, int> u;
        
        for(auto &x : s)                            u[x]++;
        
        int charPresentInS = 0;
        
        for(auto &x : t) {
           
            if(u[x] > 0) {
                u[x]--;
                charPresentInS++;
            }
        }
        
        count = m - charPresentInS;
        return count;
    }
    
};