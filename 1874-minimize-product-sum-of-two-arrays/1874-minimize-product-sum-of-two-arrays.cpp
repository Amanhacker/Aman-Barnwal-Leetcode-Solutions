class Solution {
public:
    
    int minProductSum(vector<int>& a1, vector<int>& a2) {
    
        int ans = 0;
        
        int n = a1.size();
        
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end(), greater<int>());
        
        for(int i=0; i<n; i++) {
            ans += a1[i] * a2[i];
        }
        
        return ans;
    }
    
};