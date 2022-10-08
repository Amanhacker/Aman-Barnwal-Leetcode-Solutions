class Solution {
public:
    
    int threeSumClosest(vector<int>& a, int tar) {
    
        int ans;
        
        int n = a.size();
        sort(a.begin(), a.end());
        
        int prevSum = a[0] + a[1] + a[n-1];
        
        for(int i=0; i<n-2; i++) {
            
            // Now, use Binary Search
            int start = i + 1;
            int end = n - 1;
            
            while(start < end) {
                
                int curSum = a[i] + a[start] + a[end];
                
                if(curSum == tar)                       return curSum;
                else if(curSum < tar)                   start++;
                else                                    end--;
                
                if(abs(curSum - tar) < abs(prevSum - tar))          prevSum = curSum;
            }
        }
        
        ans = prevSum;
        return ans;
    }
    
};