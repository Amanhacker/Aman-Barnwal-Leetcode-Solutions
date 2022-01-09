class Solution {
public:
    
    // Using Multiset
    
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
    
        int n = h.size();
        
        multiset<int> s;
        int i = 0;
        
        for( ; i<n-1; i++) {
            
            int jumpHeight = h[i + 1] - h[i];
            if(jumpHeight < 0)                          continue;
            
            s.insert(jumpHeight);
            
            if(s.size() > ladders) {
                
                bricks -= *s.begin();
                s.erase(s.begin());
            }
            
            if(bricks < 0)                              return i;
        }
        
        return i;
    }
    
};
