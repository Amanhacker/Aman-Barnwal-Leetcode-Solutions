class Solution {
public:
    
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
    
        vector<int> res;
        
        int n = points.size();
        int m = points[0].size();
        
        for(int i=0; i<queries.size(); i++) {
            
            int x1 = queries[i][0];
            int y1 = queries[i][1];
            
            int r1 = queries[i][2];
            
            int count = 0;
            
            for(int j=0; j<points.size(); j++) {
                
                int x = points[j][0];
                int y = points[j][1];
                
                int d = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
                
                if(d <= r1 * r1)                                         count++;
            }
            
            res.push_back(count);
        }
        
        return res;
    }
    
};