class Solution {
public:
    
    bool checkValidString(string s) {
    
        int n = s.length();
        stack<int> open, star;
        
        for(int i=0; i<n; i++) {
            
            if(s[i] == '(')                                         open.push(i);
            else if(s[i] == '*')                                    star.push(i);
            else {
                
                if(open.empty() == false)                           open.pop();
                else if(star.empty() == false)                      star.pop();
                else                                                return false;
            }
        }
        
        // Now process leftover opening brackets
        while(open.empty() == false) {
            
            if(star.empty() == true)                                return false;
            
            else if(open.top() < star.top()) {
                
                open.pop();
                star.pop();
            }
            
            // CASE: open.top() > star.top()
            
            else                                                    return false;
        }
        
        return true;
    }
    
};