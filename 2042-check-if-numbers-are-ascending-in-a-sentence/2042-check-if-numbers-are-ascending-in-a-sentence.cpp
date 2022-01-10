class Solution {
public:
    
    bool areNumbersAscending(string s) {
        
        int prev = 0, cur = 0;
        
        for (auto ch : s) {
            
            if(isdigit(ch) == true)                    cur = cur * 10 + (ch - '0');
            
            else if(cur != 0) {
                
                if (prev >= cur)                       return false;
            
                prev = cur;
                cur = 0;
            }
        }
        
        return (cur == 0 || prev < cur);
    }
    
};