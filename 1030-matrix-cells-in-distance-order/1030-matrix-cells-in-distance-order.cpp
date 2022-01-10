class Solution {
public:
    
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
    
        vector<vector<int>> res;
        
        vector<pair<int, pair<int, int>>> v;            // 1st dist - Dist, 2nd arg - co-ordinate
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                
                int dist = abs(i -rCenter) + abs(j - cCenter);
                v.push_back({dist, {i, j}});
            }
        }
        
        sort(v.begin(), v.end());
        
        vector<int> temp;
        
        for(auto &x : v) {
        
            temp.push_back(x.second.first);
            temp.push_back(x.second.second);
            
            res.push_back(temp);
            temp.clear();
        }
        
        return res;
    }
    
};