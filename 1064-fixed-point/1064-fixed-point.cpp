class Solution {
public:
   
    int fixedPoint(vector<int>& a) {
    
        int res = -1;
        
        // Find the smallest index i such that a[i] = i
        int n = a.size();
        
        int start = 0, end = n - 1;
        
        while(start <= end) {
            
            int mid = start + (end - start) / 2;
            
            if(a[mid] == mid) {
                res = mid;
                end = mid - 1;
            }
            
            else if(a[mid] < mid)                               start = mid + 1;
            else                                                end = mid - 1;
        }
        
        return res;
    }
    
};