class Solution {
public:
    
    vector<int> arraysIntersection(vector<int>& a1, vector<int>& a2, vector<int>& a3) {
    
        vector<int> res;
        
        for(int i=0; i<a1.size(); i++) {
            
            auto it2 = find(a2.begin(), a2.end(), a1[i]);
            auto it3 = find(a3.begin(), a3.end(), a1[i]);
            
            if(it2 != a2.end() && it3 != a3.end())                          res.push_back(a1[i]);
        }
        
        return res;
    }
    
};