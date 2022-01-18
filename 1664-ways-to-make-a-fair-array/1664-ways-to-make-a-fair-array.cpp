class Solution {
public:
    
    int waysToMakeFair(vector<int>& a) {
    
        int count = 0;
        int n = a.size();
        
        vector<int> left(2), right(2);
        
        for(int i=0; i<n; i++)                                  right[i % 2] += a[i];
        
        for(int i=0; i<n; i++) {
            
            right[i % 2] -= a[i];
            
            if(left[0] + right[1] == left[1] + right[0])        count++;
            
            left[i % 2] += a[i];
        }
        
        return count;
    }
    
};