class Solution {
public:
    
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    
        vector<int> res;
        set<int> w;
        
        unordered_map<int, int> u;              // 1st arg - element, 2nd arg - No.of arrays in which this element is present
        
        for(auto &x : nums1) {
            if(w.find(x) == w.end())            u[x]++;
            w.insert(x);
        }
        
        w.clear();
        
        for(auto &x : nums2) {
            if(w.find(x) == w.end())            u[x]++;
            w.insert(x);
        }
        
        w.clear();
        
        for(auto &x : nums3) {
            if(w.find(x) == w.end())            u[x]++;
            w.insert(x);
        }
        
        for(auto &x : u) {
            if(x.second >= 2)                   res.push_back(x.first);
        }
        
        return res;
    }
    
};