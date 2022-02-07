class Solution {
public:
    
    int twoSumLessThanK(vector<int>& a, int k) {
    
        int sum = -1;
        int n = a.size();
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                
                if(a[i] + a[j] < k)                         sum = max(sum, a[i] + a[j]);
            }
        }
        
        return sum;
    }
    
};