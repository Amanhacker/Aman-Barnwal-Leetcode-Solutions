class Solution {
public:
  
    int maxProfit(vector<int>& prices, int fee) {
    
        int n = prices.size();
        
        int cash = 0;
        int hold = -prices[0];                // Buy here first stock initially
        
        // Initially we have negative hold cash because we have to buy first before making any profit
        
        for(int i=1; i<n; i++) {
            
            cash = max(cash, hold + prices[i] - fee);               // Sell the stock
            hold = max(hold, cash - prices[i]);                     // Holding the stock
        }
        
        return cash;
    }
    
};