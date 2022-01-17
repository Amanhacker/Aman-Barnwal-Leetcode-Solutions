class Solution {
public:
    
    vector<int> partitionLabels(string s) {
    
        vector<int> res, pos(26, 0);
        int n = s.length();
        
        for(int i=0; i<n; i++)                              pos[s[i] - 'a'] = i;
        
        int i=0, ind = INT_MIN, lastInd = 0;
        
        for( ; i < n; i++) {

            ind = max(ind, pos[s[i] - 'a']);
            
            if(ind == i)                                    res.push_back(i - exchange(lastInd, i + 1) + 1);    
        }
        
        return res;
    }
    
};