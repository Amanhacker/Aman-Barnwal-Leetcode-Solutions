class Solution {
public:
    
    int countOdds(int low, int high) {
    
        int count = 0;
        
        if(low % 2 == 1 && high % 2 == 1) {
            count += ( (high - 1) - (low + 1) ) / 2;
            count += 2;
        }   
        
        else if(low % 2 == 0 && high % 2 == 0) {
            count += (high - low) / 2;
        }
        
        // Any one of them is odd
        else {
            count += 1;
            count += (high - low) / 2;
        }
        
        return count;
    }
    
};