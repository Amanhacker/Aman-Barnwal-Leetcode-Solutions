class Solution {
public:
    
    int minOperations(int n) {
    
        // if n is even, then we have to make all elements equal to avg of (n/2 - 1)th and (n/2)th element
        // if n is odd, then we have to make all elements qual to (n/2)th element
        
        // if n is even or odd, we have to make all elements equal to n
        
        return (n * n) / 4;
    }
    
};