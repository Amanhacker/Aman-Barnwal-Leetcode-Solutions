class Solution {
public:
   
    int trap(vector<int>& a) {
    
        int area = 0;
        int n = a.size();
        
        vector<int> left(n), right(n);
        
        int maxi = INT_MIN;
        
        for(int i=0; i<n; i++) {
            maxi = max(a[i], maxi);
            left[i] = maxi;
        }
        
        maxi = INT_MIN;
        
        for(int i=n-1; i>=0; i--) {
            maxi = max(a[i], maxi);
            right[i] = maxi;
        }
        
        for(int i=0; i<n; i++) {
            area += abs(min(left[i], right[i]) - a[i]);
        }
       
        return area;
    }
    
};