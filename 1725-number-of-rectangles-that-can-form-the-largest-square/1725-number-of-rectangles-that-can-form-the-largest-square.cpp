class Solution {
public:
    
    int countGoodRectangles(vector<vector<int>>& rect) {
    
        int count = 0;
        unordered_map<int, int> u;
        
        int maxLen = INT_MIN;
        
        for(int i=0; i<rect.size(); i++) {
            
            int side = min(rect[i][0], rect[i][1]);
            maxLen = max(maxLen, side);
            
            u[side]++;
        }
        
        return u[maxLen];
    }
    
};