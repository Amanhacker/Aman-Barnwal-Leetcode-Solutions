class Solution {
public:
   
    bool isValid(string s) {
    
        int n = s.length();
        
        if(n == 0)                                  return true;
        
        stack<char> w;
        
        for(int i=n-1; i>=0; i--) {
            
            char x = s[i];
            
            if(x == ')' || x == ']' || x == '}')         w.push(x);
            
            else {
                
                if(w.size() == 0)                       return false;
                
                char temp = w.top();

                if(x == '(' && temp == ')')              w.pop();  
                else if(x == '{' && temp == '}')         w.pop();  
                else if(x == '[' && temp == ']')         w.pop();  
                else                                     return false;
            }
        }
        
        return (w.size() == 0);
    }
    
};