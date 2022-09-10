class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    
        vector<vector<int>> res;
        
        int n = points.size();
        int m = points[0].size();
        
        // Max Heap
        priority_queue<tuple<int, int, int>> pq;  
        
        for(auto &x : points) {

            int x1 = x[0];
            int y1 = x[1];

            int sqrtDist = x1*x1 + y1*y1;
            pq.push({sqrtDist, x1, y1});
        }
        
        while(pq.empty() == false && pq.size() > k) {
            pq.pop();
        }
        
        vector<int> path;
        
        while(pq.empty() == false) {
            
            tuple<int, int, int> t = pq.top();
            pq.pop();
            
            int x2 = get<1>(t);
            int y2 = get<2>(t);
            
            path.push_back(x2);
            path.push_back(y2);
            
            res.push_back(path);
            path.clear();
        }
        
        return res;
    }
    
};