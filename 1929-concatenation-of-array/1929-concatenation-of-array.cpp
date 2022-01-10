class Solution {
public:
    
    vector<int> getConcatenation(vector<int>& a) {

        int n = a.size();
        vector<int> res(2*n);
        
        for(int i=0; i<n; i++) {
            res[i] = a[i];
            res[i + n] = a[i];            
        }
        
        return res;
    }
    
    
};