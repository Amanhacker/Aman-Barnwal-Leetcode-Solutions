class Solution {
public:
    
    int smallestEqual(vector<int>& v) {
    
        int n = v.size();
        
        for(int i=0; i<n; i++) {
            if(i % 10 == v[i])                          return i;
        }
        
        return -1;
    }
    
};