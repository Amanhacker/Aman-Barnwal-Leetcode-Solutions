class Solution {
public:
    
    int countElements(vector<int>& nums) {
    
        int res = 0;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=1; i<n-1; i++) {
            if(nums[0] < nums[i] && nums[i] < nums[n-1])                res++;
        }
        
        return res;
    }
    
};