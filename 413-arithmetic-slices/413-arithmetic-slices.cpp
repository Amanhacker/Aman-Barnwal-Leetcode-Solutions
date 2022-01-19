class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& a) {
    
        int count = 0;
        int n = a.size();
        
        if(n <= 1)                                      return 0;  
        
        int diff = a[1] - a[0];
        int start = 0;
        
        for(int i=1; i<n; i++) {
            
            int start = i - 1;
            bool flag = false;
            
            while(i < n && a[i] - a[i-1] == diff) {
                i++;
                flag = true;
            }
            
            if(i < n && a[i] - a[i-1] != diff) {
                diff = a[i] - a[i-1];
            }
            
            int end = i - 1;
            
            if(flag == true) {
               
                // Equal subarray is from [start, end]
          
                int len = end - start + 1;
                
                if(len == 3)                    count += 1;
                
                if(len > 3) {
                  
                    // No of subarrays of len 3 = len - 3 + 1
                    // No of subarrays of len 4 = len - 4 + 1, and so on
                    
                    int temp = 3;
                    
                    while(len - temp + 1 > 0) {
                        count += (len - temp + 1);
                        temp++;
                    }
                }   
                
                if(i == n)                      break;
                i = i - 1;
            }
        }
        
        return count;
    }
    
};

// 1 2 3 5 6