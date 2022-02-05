class Solution {
public:
    
    vector<int> findDuplicates(vector<int>& a) {
    
        vector<int> res;
        int n = a.size();
        
        unordered_map<int, int> u;
        
        for(auto &x : a)                                u[x]++;
        
        for(auto &x : u) {
            if(x.second >= 2)                           res.push_back(x.first);
        }
        
        return res;
    }
    
};