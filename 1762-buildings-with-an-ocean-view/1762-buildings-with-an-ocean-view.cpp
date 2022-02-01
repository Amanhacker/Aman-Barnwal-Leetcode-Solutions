class Solution {
public:
    
    vector<int> findBuildings(vector<int>& a) {
    
        vector<int> res, maxR;
        int n = a.size();
        
        for(int i=n-1; i>=0; i--) {
            if(res.empty() == true || a[i] > a[res.back()])                res.push_back(i);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
};