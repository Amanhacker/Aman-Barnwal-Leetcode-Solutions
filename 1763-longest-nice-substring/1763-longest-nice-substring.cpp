class Solution {
public:
    
    string longestNiceSubstring(string s) {
    
        string res = "";
        int n = s.length();
        
        int ans = 0;
        set<char> w;
        
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                
                // Substring starts at index i and ends at index j i.e [i, j]
                string temp = s.substr(i, j - i + 1);
                bool flag = true;
     
                w.clear();
                for(auto &x : temp)                                 w.insert(x);
                
                for(auto &x : w) {
                    
                    char ch;
                    
                    if(islower(x))                                  ch = toupper(x);
                    else if(isupper(x))                             ch = tolower(x);

                    if(w.find(ch) == w.end())                       flag = false;     
                }
                
                if(flag == true) {
                    
                    if(ans < temp.size()) {
                        ans = temp.size();
                        res = temp;
                    }
                }
            }
        }
        
        return res;
    }
    
};