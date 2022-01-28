class Solution {
public:
    
    int minOperations(int n) {
    
        // if n is even, then we have to make all elements equal to avg of (n/2 - 1)th and (n/2)th element
        // if n is odd, then we have to make all elements qual to (n/2)th element
        
        // if n is even or odd, we have to make all elements equal to n
        
        int res = 0;
        vector<int> v(n);
        
        for(int i=0; i<n; i++)                                  v[i] = (2 * i + 1);
        
        for(int i=0, j=n-1; i < j; i++, j--) {
            res += (v[j] - v[i]) / 2;
        }
        
        return res;
    }
    
};