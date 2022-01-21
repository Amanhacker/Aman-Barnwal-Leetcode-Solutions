class Solution {
public:
    
    void nextPermutation(vector<int>& a) {
    
        int n = a.size();
        if(n == 0)                                          return;
        
        int i;
        
        // In reverse order, find the first number which is in increasing trend
        for(i=n-2; i>=0; i--) {
            if(a[i] < a[i + 1])                             break;
        }

        // Reverse all the numbers after violated number
        reverse(a.begin() + i + 1, a.end());
        
        // If violated number not found, bcz we have reversed the whole array, then return
        if(i == -1)                                         return;

        // Else, find the 1st no larger than violated number
        auto it = upper_bound(a.begin() + i + 1, a.end(), a[i]);
        swap(a[i], *it);
        
        return;
    }
    
};