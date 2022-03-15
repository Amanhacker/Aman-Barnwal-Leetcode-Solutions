class Solution {
public:
    
    int minSubArrayLen(int target, vector<int>& a) {
    
        int res = INT_MAX;
        int n = a.size();
        
        int start = 0, end = 0;
        int sum = 0;
        
//         0 1 2 3 4  5
        
//         2 3 1 2 4  3
//         2 5 6 8 12 15
            
        while(start < n && end < n) {
            
            if(sum >= target) {
                
                end--;
                
                cout << start << " " << end << endl;

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
        
        // cout << start << " " << end << endl;
        cout << res << endl;
        end--;
        
        while(sum >= target) {
            
            // end--;
            
            cout << start << " " << end << endl;
            res = min(res, end - start + 1);
            
            sum -= a[start];
            start++;
        }
        
        if(res == INT_MAX)                                      return 0;
        return res;
    }
    
};