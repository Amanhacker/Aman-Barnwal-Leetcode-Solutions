class Solution {
public:
    
    int minSubArrayLen(int target, vector<int>& a) {
    
        int res = INT_MAX;
        int n = a.size();
        
        int start = 0, end = 0;
        int sum = 0;
        
        while(start < n && end < n) {
            
            if(sum >= target) {
                
                end--;
                res = min(res, end - start + 1);
                
                sum -= a[start];
                
                start++;
                end++;
            }
            
            else {
                
                // We need to add element to our search space
                sum += a[end];
                end++;
            }
        }
        
        end--;
        
        while(sum >= target) {
            
            res = min(res, end - start + 1);
            
            sum -= a[start];
            start++;
        }
        
        if(res == INT_MAX)                                      return 0;
        return res;
    }
    
};