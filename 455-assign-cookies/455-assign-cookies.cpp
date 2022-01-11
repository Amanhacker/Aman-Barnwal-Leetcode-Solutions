class Solution {
public:
    
    int findContentChildren(vector<int>& g, vector<int>& s) {
    
        int count = 0;
        
        sort(g.begin(), g.end());               // Greed Factor
        sort(s.begin(), s.end());               // Size of Cookie
        
        int n = g.size();
        
        for(int i=0, j=0; i<n && j<s.size(); ) {
            
            if(g[i] <= s[j]) {
                count++;
                j++;
                i++;
            }
            
            else if(g[i] > s[j]){
                j++;
            }
            
        }
        
        return count;
    }
    
};