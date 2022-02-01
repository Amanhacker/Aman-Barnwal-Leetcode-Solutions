class Solution {
public:
    
    int maximumSwap(int num) {
    
        int res = 0;
        
        string s = to_string(num);
        
        int maxi = -1;
        int maxInd;
        
        int n = s.length();
        
        int ind = 0;
        
        while(ind < n) {
                        
             maxi = (int)(s[ind] - '0');
            
             for(int i=ind; i<n; i++) {
            
                if(maxi <= (int)(s[i] - '0')) {
                    maxi = (int)(s[i] - '0');
                    maxInd = i;
                }    
            }
            
            if((int)(s[ind] - '0') >= maxi)                                  ind++;
            
            else {
                swap(s[ind], s[maxInd]);
                break;
            }
        }
        
        res = stoi(s);
        return res;
    }
    
};