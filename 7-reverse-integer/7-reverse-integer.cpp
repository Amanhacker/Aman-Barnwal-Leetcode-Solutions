class Solution {
public:
    
    int reverse(int x) {
    
        int rev = 0;
        
        while(x) {
            
            int pop = x % 10;
            x = x / 10;
            
            // Checking for Overflow
            
            // Logic  : 
            
            //             If temp = rev * 10 +pop causes overflow, then it must be that rev >= INT_MAX/10 
            //             If rev > INT_MAX/10,  then temp = rev*10 + pop is guaranted to overflow
            //             If rev == INT_MAX/10, then temp = rev*10 + pop will overflow iff pop > 7

            //             Same applies for negative rev

            if(rev > INT_MAX/10 || (rev == INT_MAX && pop >  7) )        return 0;
            if(rev < INT_MIN/10 || (rev == INT_MIN && pop < -8) )        return 0;
            
            int temp = rev * 10 + pop;
            rev = temp;
        }
               
        return rev;
        
    }
    
};