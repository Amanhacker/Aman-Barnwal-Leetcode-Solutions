class Solution {
public:
    
    int findGCD(vector<int>& v) {
    
        int n = v.size();
        sort(v.begin(), v.end());
        
        return __gcd(v[0], v[n-1]);
    }
    
};