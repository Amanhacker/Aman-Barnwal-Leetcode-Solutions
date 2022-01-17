class Solution {
public:
    
    vector<int> partitionLabels(string s) {
    
        vector<int> res, pos(26, 0);
        int n = s.length();
        
        for(int i=0; i<n; i++)                              pos[s[i] - 'a'] = i;
        
        int maxInd = INT_MIN, lastInd = 0;
        
        for(int i=0; i<n; i++){
            
            maxInd = max(maxInd, pos[s[i] - 'a']);
            
            if(maxInd == i) {
                res.push_back(maxInd - lastInd + 1);
                lastInd = i + 1;
            }
        }
        
        return res;
    }
    
};