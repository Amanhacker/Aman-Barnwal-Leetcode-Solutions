class Solution {
public:
  
    int missingNumber(vector<int>& a) {
    
        int res;
        int n = a.size();
        
        int diffMax = INT_MIN, d;
        int ind;
        
        for(int i=1; i<n; i++) {
            
            if(diffMax < abs(a[i] - a[i-1])) {
                
                diffMax = abs(a[i] - a[i-1]);
                
                d = a[i] - a[i-1];
                ind = i;
            }
        }
        
        res = a[ind] - (d / 2);        
        return res;
    }
    
};