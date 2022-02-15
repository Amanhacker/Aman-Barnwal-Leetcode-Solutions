class Solution {
public:
   
    vector<int> minSubsequence(vector<int>& nums) {
    
        vector<int> res;
        
        // if more than one solution, then return the subsequence with Min size, and 
        // if size of two resultant subsequence is same, then return the subsequence with max total sum
        
        int n = nums.size();
        if(n <= 1)                                          return nums;
        
        sort(nums.begin(), nums.end());
        
        vector<int> preSum(n);
        int temp = 0;
        
        for(int i=0; i<n; i++) {
            
            temp += nums[i];
            preSum[i] = temp;
        }
        
        for(int j=n-1; j>=0; j--) {
            
            // Sum  of elements from 0 to (j-1)
            int sum1, sum2;
            
            if(j == 0)                                      sum1 = nums[0];
            else                                            sum1 = preSum[j-1];
            
            // Sum of elements from ( j to (n-1) )
            if(j == n-1)                                    sum2 = nums[n-1];
            else if(j == 0)                                 sum2 = preSum[n-1];
            else                                            sum2 = preSum[n-1] - preSum[j-1];
            
            if(sum2 > sum1) {
                
                // Put all elements in res
                for(int k=j; k<n; k++)                      res.push_back(nums[k]);
                break;
                
            }
        }
        
        sort(res.begin(), res.end(), greater<int>());
        return res;
    }
    
};