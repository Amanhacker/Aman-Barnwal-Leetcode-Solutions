class Solution {
public:
    
    int minAddToMakeValid(string s) {
    
        int move = 0;
        
        if(s.size() == 0)                                       return 0;
        
        stack<char> w;
        int n = s.length();
        
        w.push(s[0]);
        
        for(int i=1; i<n; i++) {
            
            if(w.empty() == true)                               w.push(s[i]);
            
            else {
                
                char top = w.top();
            
                if(s[i] == '(')                                 w.push(s[i]);
                
                else if(s[i] == ')') {
                
                    if(top == '(')                              w.pop();
                    else                                        w.push(s[i]);
                }
            }
        }
        
        move = w.size();
        return move;
    }
    
};