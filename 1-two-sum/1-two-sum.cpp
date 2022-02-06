class Solution {
public:
   
    vector<int> twoSum(vector<int>& v, int tar) {
        
        vector<int> res;
        int n = v.size();
        
        for(int i=0; i<n; i++) {
            
            int temp = tar - v[i];
            auto it = find(v.begin(), v.end(), temp);
            
            if(it != v.end() && it - v.begin() != i) {
                
                res.push_back(i);
                res.push_back(it - v.begin());
                
                break;
            }
        }
        
        return res;
    }
    
};