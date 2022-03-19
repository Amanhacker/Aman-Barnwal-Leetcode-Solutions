class Solution {
public:
    
    // Using Variable size Sliding Window
    
    int lengthOfLongestSubstring(string s) {

        int maxi = 0;
        
        int i = 0, j = 0;
        int n = s.length();
        
        map<char, int> mp;              // 1st arg : character, 2nd arg : Count of that character
        
        while(j < n) {
            
            mp[s[j]]++;
            
            // Window size, k = j - i + 1
            
            int k = j - i + 1;
            
            if(mp.size() == j - i + 1) {
                maxi = max(maxi, j - i + 1);
                j++;
            }
            
            // Since, we need to find all unique characters in the curr sliding window
            
            else if(mp.size() < j - i + 1) {
                
                // Delete all elements from index i till the condition is met mp.size() >= j - i + 1
                
                while(mp.size() < j - i + 1 && i < n) {
                    
                    mp[s[i]]--;
                    
                    if(mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                    
                    i++;
                }
                
                j++;
            }
        }
        
        return maxi;
    }
    
};