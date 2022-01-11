class Solution {
public:
    
    int findMiddleIndex(vector<int>& a) {
    
        int n = a.size();
        
        vector<int> left(n), right(n);
        
        // left[] is the cumulative sum from left to right
        // right[] is the cumulative sum from right to left
        
        left[0] = a[0];
        for(int i=1; i<n; i++)                          left[i] = a[i] + left[i-1];
        
        right[n-1] = a[n-1];
        for(int i=n-2; i>=0; i--)                       right[i] = a[i] + right[i+1];
        
        for(int i=0; i<n; i++) {
            if(left[i] == right[i])                     return i;
        }
        
        return -1;
    }
    
};