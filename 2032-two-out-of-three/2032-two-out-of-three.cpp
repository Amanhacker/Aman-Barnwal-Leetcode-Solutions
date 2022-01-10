class Solution {
public:
    
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    
        vector<int> res;
        int cnt[3][101] = {};
        
        for(auto n : nums1)                                         cnt[0][n] = 1;
        for(auto n : nums2)                                         cnt[1][n] = 1;
        for(auto n : nums3)                                         cnt[2][n] = 1;
        
        for (int i=1; i<=100; i++) {
            if(cnt[0][i] + cnt[1][i] + cnt[2][i] >= 2)              res.push_back(i);
        }
        
        return res;
    }
    
};