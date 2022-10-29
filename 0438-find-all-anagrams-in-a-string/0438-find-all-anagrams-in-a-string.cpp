class Solution {
public:
    
    vector<int> findAnagrams(string txt, string pat) {
    
        vector<int> res;
	    unordered_map<char, int> mp;
	    
	    for(auto &ch : pat)                     mp[ch]++;
	    int count = mp.size();              // Unique characters in pat
	    
	    int i = 0, j = 0;
	    
	    int k = pat.length();
	    int n = txt.length();
	    
	    while(j < n) {
	        
	        if(mp.find(txt[j]) != mp.end()) {
	            
	            mp[txt[j]]--;
	            
	            if(mp[txt[j]] == 0)             count--;
	        }
	        
	        if(j - i + 1 < k) {
	            j++;
	        }
	        
	        else if(j - i + 1 == k) {
	            
	            if(count == 0) {
	                res.push_back(i);
	            }
	            
	            // Remove ith index
	            if(mp.find(txt[i]) != mp.end()) {
	                
	                mp[txt[i]]++;
	                
	                if(mp[txt[i]] == 1)                          count++;
	            }
	            
	            i++;
	            j++;
	        }
	    }
	    
	    return res;
    }
    
};