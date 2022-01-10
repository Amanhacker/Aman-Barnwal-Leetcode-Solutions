class Solution {
public:
  
    int finalValueAfterOperations(vector<string>& v) {
    
        int res = 0;
        int n = v.size();
        
        for(int i=0; i<n; i++) {
            
            string temp = v[i];
            
            // if x++ or ++x
            if(temp[2] == '+' || temp[0] == '+')                        res++;
            else                                                        res--;
        }
        
        return res;
    }
    
};