class Solution {
public:
    
    vector<int> distinctNumbers(vector<int>& nums, int k) {
    
        vector<int> res;
        int n = nums.size();
        
        map<int, int> mp;
        
        for(int i=0; i<=k-1; i++)                               mp[nums[i]]++;
        res.push_back(mp.size());
        
        // Starting with index 1
        for(int i=0; i<n-k; i++) {
            
            // Removing a[i] element, and adding a[i+k] element at the end
            
            mp[nums[i]]--;
            
            if(mp[nums[i]] == 0)                                mp.erase(nums[i]);
            
            mp[nums[i + k]]++;
            
            res.push_back(mp.size());
        }
        
        return res;
    }
    
};