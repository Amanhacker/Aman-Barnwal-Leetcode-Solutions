class Solution {
public:
    
    int numberOfMatches(int n) {
    
        int count = 0;
        
        while(n >= 0) {
            
            if(n == 1)                                  break;
            
            if(n == 2) {
                count += 1;
                break;
            }
            
            if(n % 2 == 0) {
                // n/2 matches are played, and n/2 players are moved to next round
                count += n / 2;
                n = n / 2;
            }
            
            else {
                // if n is odd
                
                count += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
        }
        
        return count;
    }
    
};