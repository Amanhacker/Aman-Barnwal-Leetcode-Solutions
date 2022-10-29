//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int search(string pat, string txt) {
	
	    int res = 0;
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
	                res++;
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends