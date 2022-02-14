class Solution {
public:
   
    int reachNumber(int target) {
    
        if(target == 0)                                             return 0;
        
        target = abs(target);
        int steps = 0, sum = 0;
        
        
        while(sum < target) {
            sum += steps;
            steps++; 
        }
        
        // Reach till the point when (sum - target) % 2 == 0
        while( (sum - target) % 2 == 1 ) {
            sum += steps;
            steps++;
        }
        
        return (steps - 1);
    }
    
};