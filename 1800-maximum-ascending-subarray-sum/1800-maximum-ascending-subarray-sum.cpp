class Solution {
public:
    
    int maxAscendingSum(vector<int>& a) {
    
        int ans = 0;
        int n = a.size();
        
        // Find all ascending subarray
        for(int i=0; i<n; i++) {
            
            // Subarray starts at index i
            int k = i, sum = a[i];
            
            while(k < n-1) {
                
                if(a[k] < a[k+1]) {
                    sum += a[k+1];
                    k++;
                }    
                else                                break;
            }
            
            ans = max(ans, sum);
        }
        
        return ans;
    }
    
};