class Solution {
public:
    
    vector<int> findAnagrams(string txt, string pat) {
    
        vector<int> res;
	    int n = txt.length();
	    
	    // Find count of occurences of anagrams of word pat in the text
	    
	    // Here, window size = pat.length()
	    int k = pat.length();
	    
	    unordered_map<char, int> mp;               // 1st arg - character, 2nd arg - Freq of that character
	   
	    for(auto &x : pat)              mp[x]++;
	    
	    // Using Sliding Window technique
	    
	    int i = 0, j = 0;
	    int count = mp.size();          // No.of distinct characters in pattern
	    
	   
	    while(j < n) {
	   
	        // if txt[j] is found in map, then decrease the freq of txt[j] by 1 in map
	        if(mp.find(txt[j]) != mp.end()) {
	            
	            mp[txt[j]]--;
	            
	            // If txt[j] don't occur in map anymore, then we have to decrease no.of distinct char by 1
	            if(mp[txt[j]] == 0)                     count--;
	        }
	        
	        if(j - i + 1 < k) {
	            j++;
	        }
	        
	        // if size of window is equal to k
	        
	        else if(j - i + 1 == k) {
	            
	            // If there is no remaining character which remains in txt substring and present in pat
	            
	            if(count == 0) {
	                res.push_back(i);
	            }
	            
	            // We need to remove ith index from the next window
	            
	            // if txt[i] is found in txt, then increment the freq of txt[i] in map by 1
	            if(mp.find(txt[i]) != mp.end()) {
	                
	                mp[txt[i]]++;
	                
	                if(mp[txt[i]] == 1)                 count++;
	            }
	            
	            // Slide the window by 1 unit to its right
	            
	            i++;
	            j++;
	        }
	    } 
	    
	    return res;
    }
};