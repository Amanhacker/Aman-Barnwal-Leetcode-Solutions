class Solution {
public:
    
    string helper(string s) {
        
        stack<char> w;
        
        for(auto it : s) {
            
            if(it != '#')                      w.push(it);
            else if(w.empty() == false)        w.pop();
        }
        
        string ans = "";
        
        while(w.empty() == false) {
            ans.push_back(w.top());
            w.pop();
        }
        
        return ans;
    }
    
    bool backspaceCompare(string s, string t) {
    
        return ( helper(s) == helper(t) );
    }
    
};