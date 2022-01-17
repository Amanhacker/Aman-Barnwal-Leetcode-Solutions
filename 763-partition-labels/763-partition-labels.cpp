class Solution {
public:
    
    vector<int> partitionLabels(string s) {
    
        vector<int> res, pos(26, 0);
        int n = s.length();
        
        // We record the last position for each letter
        for(int i=0; i<n; i++)                              pos[s[i] - 'a'] = i;
        
        int maxInd = INT_MIN, lastInd = 0;
        
        // we keep the maximum position of the letters we have seen so far. 
        // If the pointer exceeds the maximum position, we found the part.
        
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