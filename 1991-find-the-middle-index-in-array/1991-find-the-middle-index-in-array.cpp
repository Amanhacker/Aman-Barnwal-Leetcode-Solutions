class Solution {
public:
    
    int findMiddleIndex(vector<int>& a) {
    
        int ans = INT_MAX;
        int n = a.size();
        
        
        for(int i=0; i<n; i++) {
    
            // Taking i as middleIndex
            int leftSum = 0, rightSum = 0;
            
            // Calculate leftSum
            if(i == 0)                                  leftSum = 0;
            else {
                for(int k=0; k<i; k++)                  leftSum += a[k];
            }
            
            // Calculate rightSum
            if(i == n-1)                                rightSum = 0;
            else{
                for(int k=i+1; k<n; k++)                rightSum += a[k];
            }
                    
            if(leftSum == rightSum)                     ans = min(ans, i);                
        }
        
        if(ans != INT_MAX)                              return ans;
        else                                            return -1;
    }
    
};