class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
    
        vector<vector<int>> res;
        vector<int> path;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        if(n <= 1)                                                                    return res;
        
        for(int i=0; i<nums.size()-2; i++) {
        
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                
                int start = i + 1, end = n - 1;

                // Using Two Pointer method
                while(start < end) {

                    if(nums[start] + nums[end] == -nums[i]) {

                        if(find(res.begin(), res.end(), path) == res.end()) {
                            
                            path.push_back(nums[i]);
                            path.push_back(nums[start]);
                            path.push_back(nums[end]);
                            
                            res.push_back(path);
                            path.clear();
                        }               

                        while(start < end && nums[start] == nums[start + 1])              start++;
                        while(start < end && nums[end] == nums[end - 1])                  end--;

                        start++;
                        end--;
                    }

                    else if(nums[start] + nums[end] < -nums[i]) {
                        start++;
                    }
                    else if(nums[start] + nums[end] > -nums[i]) {
                        end--;
                    }
                }
            }
            
        }
        
        
        return res;
    }
    
};