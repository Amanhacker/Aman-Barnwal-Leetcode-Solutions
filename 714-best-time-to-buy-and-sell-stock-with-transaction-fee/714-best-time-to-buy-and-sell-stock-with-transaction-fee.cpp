class Solution {
public:
  
    int maxProfit(vector<int>& a, int fee) {
    
        int n = a.size();
        
        int oldBuyProfit = -a[0];
        int oldSellProfit = 0;                // Buy here first stock initially
        
        // Initially we have negative hold cash because we have to buy first before making any profit
        
        for(int i=1; i<n; i++) {
            
            int newBuyProfit = 0, newSellProfit = 0;
            
            if(oldSellProfit - a[i] > oldBuyProfit)             newBuyProfit = oldSellProfit - a[i];
            else                                                newBuyProfit = oldBuyProfit;
            
            if(oldBuyProfit + a[i] - fee > oldSellProfit)       newSellProfit = oldBuyProfit + a[i] - fee;
            else                                                newSellProfit = oldSellProfit;
            
            oldBuyProfit = newBuyProfit;
            oldSellProfit = newSellProfit;
        }
        
        return oldSellProfit;
    }
    
};