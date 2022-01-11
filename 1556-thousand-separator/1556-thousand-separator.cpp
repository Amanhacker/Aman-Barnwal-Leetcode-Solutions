class Solution {
public:
    
    string thousandSeparator(int n) {
    
        string res = "";
        
        string temp = to_string(n);
        int siz = temp.size();
        
        int c = 0;
        
        for(int i=siz-1; i>=0; i--) {
            
            res += temp[i];
            
            c++;
            if(c % 3 == 0 && i > 0)                     res += '.';
        }
            
        reverse(res.begin(), res.end());        
        return res;
    }
    
};