class Solution {
public:
    
    int maxLengthBetweenEqualCharacters(string s) {
    
        int maxi = -1;
        vector<int> v(26, -1);
        
        for (int i=0; i<s.size(); i++) {
            
            if(v[s[i] - 'a'] == -1)                            v[s[i] - 'a'] = i;
            else                                               maxi = max(maxi, abs(v[s[i] - 'a'] - i) - 1);      
        }
        
        return maxi;
    }
    
};