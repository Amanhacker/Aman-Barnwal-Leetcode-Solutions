class Solution {
public:
   
    int reachNumber(int target) {
    
        target = abs(target);
        int i = 0;                                  // ith move
        
        while(target > 0) {
            
            i++;
            target -= i; 
        }
       
        if(target % 2 == 0)                                     return i;
        else                                                    return (i + 1) + (i % 2);
    }
    
};