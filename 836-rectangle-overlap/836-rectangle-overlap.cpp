class Solution {
public:
  
    // Find the intersection interval of interval range
    
    int findIntersection(vector<vector<int>> interval) {

        int res = 0;
        int n = interval.size();
        
        int l = interval[0][0];
        int r = interval[0][1];
        
        for(int i=1; i<n; i++) {
            
            if(interval[i][0] > r || interval[i][1] < l)                return -1;
            
            else {
                
                // Update l and r
                
                l = max(l, interval[i][0]);
                r = min(r, interval[i][1]);
            }
        }
        
        res = abs(r - l);
        return res;
    }
    
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
    
        int x1, x2, y1, y2;
        
        vector<vector<int>> xInterval, yInterval;
        vector<int> path;
        
        path.push_back(r1[0]);
        path.push_back(r1[2]);
        
        xInterval.push_back(path);
        path.clear();
        
        path.push_back(r1[1]);
        path.push_back(r1[3]);
        
        yInterval.push_back(path);
        path.clear();
        
        path.push_back(r2[0]);
        path.push_back(r2[2]);
        
        xInterval.push_back(path);
        path.clear();
        
        path.push_back(r2[1]);
        path.push_back(r2[3]);
        
        yInterval.push_back(path);
        path.clear();
        
        int dx = findIntersection(xInterval);
        int dy = findIntersection(yInterval);
        
        return (dx > 0 && dy > 0);
    }
    
};