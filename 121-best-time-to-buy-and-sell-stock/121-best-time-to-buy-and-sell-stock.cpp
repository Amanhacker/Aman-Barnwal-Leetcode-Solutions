class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
    
        int maxi = 0;
        int n = prices.size();
        
        int mn = prices[0];                     // Minimum element from left side
        
        for(int i=1; i<n; i++) {
            maxi = max(maxi, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        
        return maxi;
    }
    
};