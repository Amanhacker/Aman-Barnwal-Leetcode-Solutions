class Solution {
public:
    
    int dominantIndex(vector<int>& nums) {
    
        int res = -1;
        
        int n = nums.size();
        int maxi = INT_MIN;
        
        for(int i=0; i<n; i++) {
            
            if(maxi < nums[i]) {
                maxi = nums[i];
                res = i;
            }
        }   
        
        for(auto &x : nums) {
            if(x != maxi && 2 * x > maxi)                       return -1;
        }
        
        return res;
    }
    
};