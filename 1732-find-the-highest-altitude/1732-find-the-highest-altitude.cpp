class Solution {
public:
    
    int largestAltitude(vector<int>& a) {
    
        int maxi = 0;
        int n = a.size();
        
        int temp = 0;
        
        for(int i=0; i<n; i++) {
            temp = temp + a[i];
            maxi = max(maxi, temp);
        }
        
        return maxi;
    }
    
};