class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& a) {
    
        int count = 0;
        int n = a.size();
        
        for(int i=2, j=1; i<n; i++) {
            
            if(a[i] - a[i-1] != a[j] - a[j-1])                      j = i;
            
            count += (i - j);
        }
        
        return count;
    }
    
};