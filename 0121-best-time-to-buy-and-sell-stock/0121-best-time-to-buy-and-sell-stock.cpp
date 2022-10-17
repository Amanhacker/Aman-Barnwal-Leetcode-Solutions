class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
    
        int res = INT_MIN;
        int n = prices.size();
        
        vector<int> maxPrice(n);
        int maxi = INT_MIN;
        
        for(int i=n-1, k=n-1; i>=0; i--) {
            maxi = max(maxi, prices[i]);
            maxPrice[k--] = maxi;
        }
        
        for(int i=0; i<n; i++) {
            res = max(res, maxPrice[i] - prices[i]);
        }
        
        return res;
    }
    
};