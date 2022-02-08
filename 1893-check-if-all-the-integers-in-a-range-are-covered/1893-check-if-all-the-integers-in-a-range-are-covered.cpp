class Solution {
public:
 
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    
        int n = ranges.size();
        map<int, int> mp;
        
        // If each integer in the inclusive range [left, right] is covered by at least one interval in ranges, then return true
        for(int i=0; i<n; i++) {
            
            if(ranges[i][0] <= left && right <= ranges[i][1])       return true;
            
            if(right < ranges[i][0] || ranges[i][1] < left)         continue;
            
            for(int k=ranges[i][0]; k<=ranges[i][1]; k++) {

                // if k lies between [left, right]
                if(left <= k && k <= right)                         mp[k]++;
            }
        }
        
        for(int i=left; i<=right; i++) {
            if(mp[i] == 0)                                           return false;
        }
        
        return true;
    }
    
};