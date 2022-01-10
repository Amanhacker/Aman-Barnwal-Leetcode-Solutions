class Solution {
public:
    
    int maxDistance(vector<int>& col) {
    
        int res;
        int n = col.size();
        
        // i is the leftmost position of the color different from the last color.
        // j is the rightmost position of the color different from the first one.
        
        // Therefore, we need to return the maximum of two cases: max(j, n - i - 1), where

        int i = 0, j = n - 1; 
        
        while(col[0] == col[j])                             j--;
        while(col[n-1] == col[i])                           i++;
        
        res = max(j, n - i - 1);
        return res;
    }
    
};