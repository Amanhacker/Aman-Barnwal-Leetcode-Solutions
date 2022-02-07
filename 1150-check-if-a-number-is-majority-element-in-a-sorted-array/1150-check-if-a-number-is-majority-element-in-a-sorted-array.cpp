class Solution {
public:
    
    bool isMajorityElement(vector<int>& a, int target) {
    
        int n = a.size();
        int ct = count(a.begin(), a.end(), target);
        
        return (ct > n/2);                                        
    }
    
};