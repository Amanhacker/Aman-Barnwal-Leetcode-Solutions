class Solution {
public:
    
    string simplifyPath(string path) {
    
        string res = "";
        
        // '.' refers to the current directory
        // '..' refers to the directory up a level
        // '//' are treated as single slash '/'
        // Other formats are treated as file names
        
        int n = path.length();
        
        stack<string> st;
        string temp = "";
        
        if(path[n-1] != '/') {
            path += '/';
            n++;
        }
        
        // First char is always '/'
        for(int i=1; i<n; i++) {
            
            if(path[i] == '/') {
                
                if(temp == "" || temp == ".") {
                    temp = "";
                    continue;
                }
               
                else if(temp == "..") {
                    if(st.empty() == false)                           st.pop();
                }
                
                else                                                  st.push(temp);
                
                temp = "";
            }
            
            else {
                temp += path[i];
            }
        }
        
        // Now, make the final string by appending each element at the front from stack
        
        while(st.empty() == false) {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        if(res.length() == 0) {
            res = "/";
        }
        
        return res;
    }
    
};