class Solution {
public:
    
    // Same as Longest substring with 2 unique characters using Sliding Window concept
    
    int totalFruit(vector<int>& s) {
    
        int maxi = -1;
        int k = 2;
        
        int i = 0, j = 0;
        int n = s.size();

        if(n <= 2)                          return n;
        
        map<int, int> mp;                  // 1st arg - char, 2nd arg - count of that char

        while(j < n) {

            mp[s[j]]++;

            if(mp.size() <= k) {
                maxi = max(maxi, j - i + 1);
                j++;
            }

            else if(mp.size() > k) {

                // Delete all those char starting from index i till the condition becomes mp.size() <= k
                while(mp.size() > k && i < n) {

                    mp[s[i]]--;

                    // If frequency of char s[i] becomes zero, then we also have to decrease the char from map, 
                    // because that char s[i] is not present in my current sliding window
                    
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

    
        

