class Solution {
public:

    static bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
        if(a.first == b.first)              return a < b;
        else                                return a.first > b.first;
    }
    
    int mostFrequentEven(vector<int>& nums) {
    
        int n = nums.size();
        
        if(n == 0)                          return -1;
        
        if(n == 1) {
            if(nums[0] % 2 == 0)            return nums[0];
            else                            return -1;
        }
        
        unordered_map<int, int> mp;
        for(auto &x : nums)                 mp[x]++;
        
        vector<pair<int, int>> v;       // 1st - freq, 2nd - value
        
        for(auto &x : mp) {
            if(x.first % 2 == 0)            v.push_back({x.second, x.first});
        }   
        
        sort(v.begin(), v.end(), cmp);
        
        if(v.size() == 0)                   return -1;
        for(auto &x : v)                    return x.second;
        
        
        return -1;
    }
    
};