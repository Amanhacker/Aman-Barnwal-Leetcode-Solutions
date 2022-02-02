class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& v) {
    
        vector<vector<int>> res;
        int n = v.size();
        
        if(n == 0)                                return res;
        
        sort(v.begin(), v.end());
        
        res.push_back(v[0]);
        
        int j = 0;
        
        for(int i=1; i<n; i++) {
            
            // If intervals are overlapping
            if(res[j][1] >= v[i][0])                 res[j][1] = max(res[j][1], v[i][1]);
            
            else {
                
                res.push_back(v[i]);
                j++;
            }
        }
        
        return res;
    }
    
};