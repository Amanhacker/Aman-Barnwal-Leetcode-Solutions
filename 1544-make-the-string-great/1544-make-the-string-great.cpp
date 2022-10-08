class Solution {
public:
    
    string makeGood(string s) {
    
        string res = "";
        stack<char> w;
        
        for(auto &x : s) {
            
            if(w.empty() == true)                   w.push(x);
            else if(abs(w.top() - x) == 32)         w.pop();
            else                                    w.push(x);
        }
        
        while(w.empty() == false) {
            res += w.top();
            w.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
};