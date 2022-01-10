class Solution {
public:
    
    int maxProductDifference(vector<int>& a) {
        
        int res;
        int n = a.size();
        
        sort(a.begin(), a.end());
        
        res = (a[n-1] * a[n-2]) - (a[0] * a[1]);
        return res;
    }
    
};