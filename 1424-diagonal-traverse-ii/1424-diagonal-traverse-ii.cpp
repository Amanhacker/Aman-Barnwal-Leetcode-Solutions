class Solution {
public:
    
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    
        vector<int> res;
        
        // Form Min Heap
        using pi = pair<int, vector<int>>;
       
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        unordered_map<int, vector<int>> u;
        
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[i].size(); j++) {
                u[i + j].push_back(mat[i][j]);
            }
        }
    
        for(auto &x : u) {
            
            vector<int> temp = x.second;
            
            reverse(temp.begin(), temp.end());
            pq.push({x.first, temp});
        }
        
        while(pq.empty() == false) {
            
            pi t = pq.top();
            pq.pop();
            
            vector<int> diagonalVec = t.second;
            for(auto &x : diagonalVec)                  res.push_back(x);
        }
        
        return res;
    }
    
};