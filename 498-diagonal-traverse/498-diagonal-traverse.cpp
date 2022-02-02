class Solution {
public:
    
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    
        vector<int> res;
        
        int n = mat.size();
        int m = mat[0].size();
        
        unordered_map<int, vector<int>> u;
        
        // Diagonal Traverse of the matrix
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                u[i + j].push_back(mat[i][j]);
            }
        }
    
        vector<pair<int, vector<int>>> v;
        for(auto &x : u)                                                        v.push_back({x.first, x.second});
        
        sort(v.begin(), v.end());
        
        // Now, when index is even, then push the vector in reverse order
        for(auto &x : v) {
            
            if(x.first % 2 == 1) {
                for(auto &t : x.second)                                         res.push_back(t);
            }                     
            else {
                
                vector<int> temp = x.second;
                for(auto it=temp.rbegin(); it!=temp.rend(); it++)               res.push_back(*it);
            }
        }
        
        return res;
    }
    
};