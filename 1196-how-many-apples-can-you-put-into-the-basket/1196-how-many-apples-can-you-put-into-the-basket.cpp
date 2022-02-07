class Solution {
public:
   
    int maxNumberOfApples(vector<int>& a) {
        
        int res = 0;
        int n = a.size();
        
        sort(a.begin(), a.end());
        int sum = 0;
        
        for(auto &x : a) {
            
            sum += x;
            
            if(sum <= 5000)                                 res++;
            else                                            break;
        }
        
        return res;
    }
    
};