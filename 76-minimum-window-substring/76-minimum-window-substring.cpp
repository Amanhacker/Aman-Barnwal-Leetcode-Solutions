class Solution {
public:
    
    string minWindow(string s, string t) {

        int maxi = INT_MAX;
        int n = s.length();
        
        unordered_map<char, int> mp;
        
        for(auto &x : t)                                            mp[x]++;
        
        int count = mp.size();                  // No.of unique characters in string t
        int i = 0, j = 0;
        
        string ans = "";
        
        while(j < n) {
            
            // if s[j] is already present in map
            if(mp.find(s[j]) != mp.end()) {
                
                mp[s[j]]--;
                
                if(mp[s[j]] == 0)                                    count--;
            }
            
            
            // if count is zero, then the current sliding window is one of the possible answers
            if(count == 0) {
                
                while(count == 0) {
                    
                    if(j - i + 1 < maxi) {
                        maxi = j - i + 1;
                        ans = s.substr(i, j - i + 1);
                    }
                    
                    if(mp.find(s[i]) != mp.end()) {
                        
                        mp[s[i]]++;
                        
                        if(mp[s[i]] > 0)                             count++;
                    }
                    i++;
                }
            }
            
            j++;
        }
        
        // cout << maxi << endl;
        return ans;
    }
    
};