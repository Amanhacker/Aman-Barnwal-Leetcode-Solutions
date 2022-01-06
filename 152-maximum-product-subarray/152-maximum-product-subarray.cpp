class Solution {
public:
    
    int maxProduct(vector<int>& a) {
        
       int n = a.size();
        
       if(n == 1)                                     return a[0];
        
       int cur_pdt = 1, res = INT_MIN;
       
       for (auto x : a) {
           
           cur_pdt = cur_pdt * x;
           res = max(cur_pdt, res);
           
           if(cur_pdt == 0)                            cur_pdt = 1;
       }
       
       cur_pdt = 1;
       
       for(int i=n-1; i>=0; i--) {
           
           cur_pdt = cur_pdt * a[i];
           res = max(cur_pdt, res);
           
           if(cur_pdt == 0)                            cur_pdt = 1;
       }
        
       return res;
    }
    
};