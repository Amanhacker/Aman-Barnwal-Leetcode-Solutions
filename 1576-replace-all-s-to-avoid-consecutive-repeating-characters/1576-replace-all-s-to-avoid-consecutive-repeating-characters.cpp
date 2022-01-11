class Solution {
public:
    
    string modifyString(string s) {
    
        vector<int> vis(26, 0);
        
        for(auto &x : s) {
            if(x != '?')                             vis[x - 'a'] = 1;
        }

        vector<char> letter;
        
        for(int k=0 ; k<26; k++) {
            char ch = (char)(k + 97);
            if(vis[ch - 'a'] == 0)                   letter.push_back(ch);
        }
        
        int n = s.length();
        int c = 0;
        
        for(int i=0; i<n; i++) {
            
            if(s[i] == '?') {
                
                if(c % 2 == 0)                      s[i] = letter[0];
                else                                s[i] = letter[1];
                
                c++;
            }
        }
        
        return s;
    }
    
};