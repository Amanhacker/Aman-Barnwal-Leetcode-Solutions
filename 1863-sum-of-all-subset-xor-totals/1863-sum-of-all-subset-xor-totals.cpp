class Solution {
public:
    
    void findAllSubsets(vector<int> &a, int ind, int n, vector<int> path, vector<vector<int>> &res) {
        
        res.push_back(path);
        
        // Run a for loop from ind to n-1
        for(int i=ind; i<n; i++) {
            
            // If we pick the element at index i
            path.push_back(a[i]);
            findAllSubsets(a, i + 1, n, path, res);
            path.pop_back();
        }
        
        return;
    }
    
    int subsetXORSum(vector<int>& v) {
    
        int sum = 0;
        
        // Find all the subsets of vector v
        int n = v.size();
        
        vector<vector<int>> res;
        vector<int> path;
        
        findAllSubsets(v, 0, n, path, res);
        
        for(auto &x : res) {
            
            int t = 0;
            
            for(auto &x1 : x)                    t ^= x1;
            
            sum += t;
        }
        
        return sum;
    }
    
};