class Solution {
public:
    
    int twoSumLessThanK(vector<int>& a, int k) {
    
        int sum = -1;
        int n = a.size();
        
        sort(a.begin(), a.end());
        
        for(int i=0, j=n-1; i<j; ) {
                
            if(a[i] + a[j] < k) {
               sum = max(sum, a[i] + a[j]);
               i++;
            }   
            else                                        j--;
        }
        
        return sum;
    }
    
};