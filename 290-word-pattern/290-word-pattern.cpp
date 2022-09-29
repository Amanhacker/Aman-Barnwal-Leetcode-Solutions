class Solution {
public:
    
    bool wordPattern(string pattern, string s) {
    
        map<string, int> u1;
        map<char, int> u2;
        
        vector<char> v;
        int c1 = 1;
        
        for(auto &x : pattern) {
            
            if(find(v.begin(), v.end(), x) == v.end()) {
                u2[x] = c1++;
                v.push_back(x);
            }          
        }
                
        string res1 = "", res2 = "";
        
        for(auto &x : pattern) {
            res1 += to_string(u2[x]);
        }
        
        
        vector<string> words;
        string temp = "";
        
        for(int i=0; i<s.length(); i++) {
            
            if(s[i] != ' ') {
                temp += s[i];   
                if(i == s.length() - 1)                 words.push_back(temp);
            }
            else {
                words.push_back(temp);
                temp = "";
            }
        }
        
        c1 = 1;
        vector<string> v2;
        
        for(auto &x : words) {
            
            if(find(v2.begin(), v2.end(), x) == v2.end()) {
                u1[x] = c1++;
                v2.push_back(x);
            }  
        }
        
        for(auto &x : words) {
            res2 += to_string(u1[x]);
        }
        
        // cout << res1 << " " << res2 << endl;
        return (res1 == res2);
    }
     
};