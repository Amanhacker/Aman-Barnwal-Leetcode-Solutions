class Solution {
public:
    
    int majorityElement(vector<int>& nums) {
    
        int res;
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        for(auto &x : nums)             mp[x]++;
        
        for(auto &x : mp) {
            if(x.second > n / 2)        return x.first;
        }
        
        return -1;
    }
    
};