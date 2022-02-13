class Solution {
public:
    
    vector<bool> checkArithmeticSubarrays(vector<int>& a, vector<int>& l, vector<int>& r) {
    
        vector<bool> res;
        int n = a.size();
        
        int m = l.size();
        
        for(int i=0; i<m; i++) {
            
            int start = l[i];
            int end = r[i];
            
            // Range is from start to end
            vector<int> path;
            
            for(int j=start; j<=end; j++)           path.push_back(a[j]);    
            sort(path.begin(), path.end());
            
            bool flag = true;
            int diff = path[1] - path[0];
            
            for(int k=2; k<path.size(); k++) {
                if(diff != path[k] - path[k-1]) {
                    flag = false;
                    break;
                }
            }
            
            res.push_back(flag);
        }
        
        return res;
    }
    
};