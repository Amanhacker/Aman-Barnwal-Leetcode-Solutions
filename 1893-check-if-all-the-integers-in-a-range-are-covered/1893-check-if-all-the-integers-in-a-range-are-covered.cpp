class Solution {
public:
    
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    
        map<int, int> mp;
        
        for(auto &x : ranges) {
            
            int start = x[0];
            int end = x[1];
            
            for(int i=start; i<=end; i++)       mp[i] = 1;
        }
    
        for(int i=left; i<=right; i++) {
            if(mp[i] == 0)                      return false;
        }
        
        return true;
    }
    
};