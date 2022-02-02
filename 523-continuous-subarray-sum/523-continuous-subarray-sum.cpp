class Solution {
public:
    
    bool checkSubarraySum(vector<int>& v, int k) {
    
        int n = v.size();
      
        if(n == 0)                              return false;
        
        int sum = 0, pre = 0;
        unordered_set<int> w;
        
        for(int i=0; i<n; i++) {
            
            sum += v[i];
            
            int mod;
            
            if(k == 0)                          mod = sum;
            else                                mod = sum % k;
            
            if(w.count(mod))                    return true;
            
            w.insert(pre);
            pre = mod;
        }
        
        return false;
    }
    
};