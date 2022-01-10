class Solution {
public:
    
    int maxProductDifference(vector<int>& a) {
        
        int res;
        int n = a.size();
        
        int max1 = INT_MIN, max2 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        
        for(int i=0; i<n; i++) {
            
            if(a[i] > max1) {
                max2 = max1;
                max1 = a[i];
            }
            
            else if(a[i] > max2) {
                max2 = a[i];
            }
            
            if(a[i] < min1) {
                min2 = min1;
                min1 = a[i];
            }
            
            else if(a[i] < min2) {
                min2 = a[i];
            }
        }
            
        res = (max2 * max1) - (min2 * min1);
        return res;
    }
    
};