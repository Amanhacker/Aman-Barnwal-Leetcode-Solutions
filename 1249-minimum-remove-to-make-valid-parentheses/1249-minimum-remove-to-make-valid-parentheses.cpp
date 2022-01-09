class Solution {
public:
    
    string minRemoveToMakeValid(string s) {
    
        string res = "";
        int n = s.length();
        
        stack<pair<char, int>> w;
        vector<char> vis(n, 0);
        
        for(int i=0; i<n; i++) {
            
            if(s[i] != '(' && s[i] != ')')                               vis[i] = 1;
            else {

                if(w.empty() == true) {
                    if(s[i] == ')')                                      vis[i] = 0;
                    else                                                 w.push({s[i], i});
                }   
                
                else {
                    
                    pair<char, int> top = w.top();
                    
                    if(s[i] == ')') {
                        
                        if(top.first == '(') {
                            
                            vis[i] = 1;
                            vis[top.second] = 1;
                            
                            w.pop();
                        }
                        else                                            w.push({s[i], i});
                    }    
                    
                    else                                                w.push({s[i], i});
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            if(vis[i] == 1)                                             res += s[i];
        }
        
        return res;
    }
    
};