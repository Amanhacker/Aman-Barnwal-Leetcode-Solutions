class Solution {
public:
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    
        vector<int> res;
        
        int n = nums1.size();
        int m = nums2.size();
        
        map<int, int> mp;
        
        for(auto &x : nums1)                mp[x]++;
        
        for(auto &x : nums2) {
            if(mp[x] > 0) {
                res.push_back(x);
                mp[x]--;
            }
        }
        
        return res;
    }
    
};