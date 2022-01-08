class Solution {
public:
   
    bool check(vector<int> &a, int mid, int k, int n) {
        
        int total = 0;
        int j = 0; 
        
        for(int i=0; i<n; i++) {
            
            while(j < n && a[j] - a[i] <= mid)                     j++;
            
            j--;
            total += j - i;                     // No.of pairs which I can form having diff <= mid
        }
        
        if(total >= k)                                              return true;
        else                                                        return false;
    }
    
    int smallestDistancePair(vector<int>& a, int k) {
    
        int n = a.size();
        sort(a.begin(), a.end());
        
        int start = 0, end = a[n-1] - a[0];
        
        while(start < end) {
        
            int mid = start + (end - start) / 2;
            
            if(check(a, mid, k, n) == true)                        end = mid;
            else                                                   start = mid + 1;
        }
        
        return start;
    }
    
};