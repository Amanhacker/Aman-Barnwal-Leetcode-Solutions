class Solution {
public:
  
    int maxProfit(vector<int>& a, int fee) {
    
        int n = a.size();
        
        // buyProfit is the state when you have extra shares i.e more buys than sells
        // sellProfit is the state when you don't have extra shares i.e no.of Buys = no.of Sells
        
        int oldBuyProfit = -a[0];
        int oldSellProfit = 0;                // Buy here first stock initially
        
        // Initially we have negative hold cash because we have to buy first before making any profit
        
        for(int i=1; i<n; i++) {
            
            int newBuyProfit = 0, newSellProfit = 0;
            
            // When you buy the ith share on oldSellProfit
            if(oldSellProfit - a[i] > oldBuyProfit)             newBuyProfit = oldSellProfit - a[i];
            else                                                newBuyProfit = oldBuyProfit;
            
            // When you sell ith share on oldBuyProfit
            if(oldBuyProfit + a[i] - fee > oldSellProfit)       newSellProfit = oldBuyProfit + a[i] - fee;
            else                                                newSellProfit = oldSellProfit;
            
            oldBuyProfit = newBuyProfit;
            oldSellProfit = newSellProfit;
        }
        
        return oldSellProfit;
    }
    
};