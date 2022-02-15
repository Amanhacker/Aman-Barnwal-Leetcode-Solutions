class Solution {
public:
    
    int removeElement(vector<int>& nums, int val) {
    
        int res = 0;
        int n = nums.size();
        
        if(n == 0)                                                        return 0;
        
        int j = n - 1;

        while(j >= 0 && nums[j] == val)                                   j--;

        if(j < 0)                                                         return 0;
        
        for(int i=0; i<=j; i++) {
            
            while(j >= 0 && nums[j] == val)                                j--;
            
            if(i > j)                                                      break;
            
            if(nums[i] == val) {
                swap(nums[i], nums[j]);
                j--;
            }
        }
        
        
        while(j >= 0 && nums[j] == val)                                    j--;

        // [0, j]
        res = j + 1;
        
        nums.resize(res);
        return res;
    }
    
};