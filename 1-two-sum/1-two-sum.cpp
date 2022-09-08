class Solution {
public:
    
    vector<int> twoSum(vector<int>& v, int tar) {
    
        vector<int> res;
        int n = v.size();
        
        for(int i=0; i<n-1; i++) {
            
            auto it = find(v.begin()+i+1, v.end(), tar - v[i]);
            
            if(it != v.end()) {
                
                int ind = it - v.begin();
                
                res.push_back(ind);
                res.push_back(i);
                
                return res;
            }
        }
        
        return res;
    }
    
};