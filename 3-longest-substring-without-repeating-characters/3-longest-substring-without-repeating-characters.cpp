class Solution {
public:
  
    int lengthOfLongestSubstring(string s) {
    
        int ans = 0;
        
        int n = s.length();
        
        // There are total 256 ASCII characters
        vector<int> dict(256, -1);
        int start = -1;
        
        for(int i=0; i<n; i++) {
            
            if(dict[s[i]] > start)                              start = dict[s[i]];
            
            dict[s[i]] = i;
            ans = max(ans, i - start);
        }
        
        return ans;
    }
    
};