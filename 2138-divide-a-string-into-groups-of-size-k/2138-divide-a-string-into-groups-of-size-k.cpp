class Solution {
public:
   
    vector<string> divideString(string s, int k, char fill) {
        
        vector<string> res;
        int n = s.length();
        
        for(int i=0; i<n; i += k) {
            
            if(i + k - 1 < n)                           res.push_back(s.substr(i, k));
           
            else {
                
                int len = (n - 1) - i + 1;
                string temp = s.substr(i, len);
                
                int rem = k - len;
                while(rem--)                        temp += fill;
                
                res.push_back(temp);
            }
        }
        
        return res;
    }
    
};