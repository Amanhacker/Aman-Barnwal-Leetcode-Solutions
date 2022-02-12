class Solution {
public:
    
    int numKLenSubstrNoRepeats(string s, int k) {
    
        int res = 0;
        
        int n = s.length();
        vector<string> v;
        
        for(int i=0; i<=n-k; i++) {
            
            // Substring is from [i, i+k-1]
            string temp = s.substr(i, k);
            
            // Check whether there is not characters
            set<char> w;
            bool flag = true;
            
            for(auto &x : temp) {
                
                if(w.find(x) != w.end()) {
                    flag = false;
                    break;
                }
                
                else                            w.insert(x);
            }
            
            if(flag == true)                    res++;
        }
        
        return res;
    }
    
};