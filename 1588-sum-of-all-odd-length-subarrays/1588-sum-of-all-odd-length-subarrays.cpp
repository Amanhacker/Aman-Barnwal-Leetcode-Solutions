class Solution {
public:
    
    int sumOddLengthSubarrays(vector<int>& a) {
    
        int sum = 0;
        int n = a.size();
        
        int l = 3;
        
        for(int i=0; i<n; i++)                  sum += a[i];

        while(l <= n) {
            
            for(int i=0; i<=n-l; i++) {
                
                int temp = 0;
                for(int j=i; j<i+l; j++)            temp += a[j];
                sum += temp;
            }
            
            l += 2;
        }
        
        return sum;
    }
    
};