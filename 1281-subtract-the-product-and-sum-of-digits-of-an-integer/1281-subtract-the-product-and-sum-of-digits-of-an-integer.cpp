class Solution {
public:
  
    int subtractProductAndSum(int n) {
    
        int res;
        
        int sum = 0, pdt = 1;
        
        while(n > 0) {
            
            sum += n % 10;
            pdt *= (n % 10);

            n = n / 10;
        }
        
        res = pdt - sum;
        return res;
    }
    
};