class Solution {
public:
    
    vector<int> findBuildings(vector<int>& a) {
    
        vector<int> res, maxR;
        int n = a.size();
        
        int maxi = a[n-1];
        maxR.resize(n);
        
        // Here, maxR[i] is the maximum element from [i + 1, n - 1]
        maxR[n-1] = 0;
        
        for(int i=n-2; i>=0; i--) {
            maxi = max(maxi, a[i + 1]);
            maxR[i] = maxi;
        }
        
        for(int i=0; i<n-1; i++) {
            if(a[i] > maxR[i])                             res.push_back(i);
        }
        
        res.push_back(n-1);
        return res;
    }
    
};