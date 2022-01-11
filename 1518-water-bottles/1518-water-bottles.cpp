class Solution {
public:
   
    int numWaterBottles(int numBottles, int numExchange) {
    
        int ans = 0;
    
        // You can exchange numExchange no.of empty bottle to get 1 full water bottle
        
        int n = numBottles;
        int m = numExchange;
        
        ans += n;
        
        while(true) {
            
            int remainingEmptyBottles = n % m;
            
            // Empty bottles can be converted to full water bottle
            ans += (n / m);
            
            n = (remainingEmptyBottles) + (n / m);
            
            if(n < m)                                           break;
        }
        
        return ans;
    }
    
};