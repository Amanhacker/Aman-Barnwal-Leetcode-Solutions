class Solution {
public:
    
    int maxDistance(vector<int>& col) {
    
        int res = INT_MIN;
        int n = col.size();
        
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(col[i] != col[j])                            res = max(res, j - i);
            }
        }
        
        return res;
    }
    
};