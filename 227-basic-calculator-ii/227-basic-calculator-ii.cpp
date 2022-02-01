class Solution {
public:
  
    int calculate(string s) {
    
        int res = 0;
        int n = s.length();

        if(n == 0)                                      return 0;
        
        int curNo = 0;
        char op = '+';
        
        stack<int> w;
        
        for(int i=0; i<n; i++) {
            
            if(isdigit(s[i]))                            curNo = (curNo * 10) + (s[i] - '0');
            
            if(!isdigit(s[i]) && !iswspace(s[i]) || i == n-1) {
                
                if(op == '-')                            w.push(-curNo);
                else if(op == '+')                       w.push(curNo);
                
                else if(op == '*') {
                    
                    int top = w.top();
                    w.pop();
                    
                    w.push(top * curNo);
                }
                
                else if(op == '/') {
                    
                    int top = w.top();
                    w.pop();
                    
                    w.push(top / curNo);
                }
                
                op = s[i];
                curNo = 0;
            }
        }
        
        while(w.empty() == false) {
            res += w.top();
            w.pop();
        }
        
        return res;
    }
    
};