class Solution {
public:
    
    int pivotIndex(vector<int>& a) {
    
        int n = a.size();
        
        int leftSum = 0, rightSum = 0, sum = 0;
        
        for(int i=0; i<n; i++)              sum += a[i];
        
        for(int i=0; i<n; i++) {
            
            rightSum = sum - leftSum - a[i];
            if(leftSum == rightSum)         return i;
            
            leftSum += a[i];
        }
        
        return -1;
    }
    
};