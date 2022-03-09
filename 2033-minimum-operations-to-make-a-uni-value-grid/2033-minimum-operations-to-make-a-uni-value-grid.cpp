class Solution {
public:

    int minOperations(vector<vector<int>>& grid, int x) {
    
        int res = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> nums;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                nums.push_back(grid[i][j]);
            }
        }
        
        sort(nums.begin(), nums.end());
        
        int siz = n * m;
        int midEle = nums[siz / 2];
        
        // Now, we have to make every element equal to midEle
        
        for(int i=0; i<siz; i++) {
            
            // Convert nums[i] element to midEle by min Operations of either adding or subtrating x
            int diff = abs(nums[i] - midEle);
            
            if(diff % x != 0)                                       return -1;
            else                                                    res += (diff / x);
        }
        
        return res;
    }
    
};