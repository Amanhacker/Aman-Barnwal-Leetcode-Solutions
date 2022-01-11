class Solution {
public:
    
    int maxAscendingSum(vector<int>& a) {
    
        int ans = a[0];
        int n = a.size();
        
        int sum = a[0];
        
        // Find all ascending subarray
        for(int i=1; i<n; i++) {
            
            if(a[i-1] < a[i])                           sum += a[i];
            else                                        sum = a[i];
            
            ans = max(ans, sum);
        }
        
        return ans;
    }
    
};