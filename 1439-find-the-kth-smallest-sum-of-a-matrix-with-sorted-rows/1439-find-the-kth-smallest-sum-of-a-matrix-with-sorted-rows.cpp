class Solution {
public:
   
    int kthSmallest(vector<vector<int>>& mat, int k) {
    
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> v = mat[0];
        
        for(int i=1; i<n; i++) {
        
            vector<int> temp;
            
            for(int j=0; j<m; j++) {
                for(auto x : v)                       temp.push_back(mat[i][j] + x);
            }

            sort(temp.begin(), temp.end());
            
            int siz = temp.size();
            int newSize = min(k, siz);
            
            v.resize(newSize);
            
            for(int i=0; i<newSize; i++)              v[i] = temp[i];
        }

        return v[k-1];
    }
    
};