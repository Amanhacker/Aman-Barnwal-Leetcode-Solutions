class Solution {
public:
    
    int maximumDifference(vector<int>& v) {
        
        int maxi = -1;
        int n = v.size();
        
        int mn = v[0];                        // Minimum element from left side
        
        for(int i=1; i<n; i++) {
            maxi = max(maxi, v[i] - mn);
            mn = min(mn, v[i]);
        }   
        
        if(maxi == 0)                         return -1;
        return maxi;
    }
    
};