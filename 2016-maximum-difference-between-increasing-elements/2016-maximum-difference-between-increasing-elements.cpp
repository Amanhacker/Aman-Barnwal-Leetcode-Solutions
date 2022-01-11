class Solution {
public:
    
    int maximumDifference(vector<int>& v) {
    
        int maxi = INT_MIN;
        
        int n = v.size();
        
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(v[i] < v[j])                     maxi = max(maxi, v[j] - v[i]);
            }
        }
        
        if(maxi == INT_MIN)                         return -1;
        return maxi;
    }
    
};