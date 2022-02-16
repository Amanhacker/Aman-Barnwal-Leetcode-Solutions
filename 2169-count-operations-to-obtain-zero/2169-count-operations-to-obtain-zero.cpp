class Solution {
public:
   
    int countOperations(int n1, int n2) {
    
        int count = 0;
        
        while(true) {
            
            if(n1 == 0 || n2 == 0)                          break;
            
            if(n1 >= n2)                                    n1 -= n2;
            else                                            n2 -= n1;
            
            count++;
        }
        
        return count;
    }
    
};