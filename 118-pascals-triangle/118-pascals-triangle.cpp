class Solution {
public:
    
    vector<vector<int>> generate(int n) {
    
        vector<vector<int>> res;
        vector<int> temp, t;
        
        temp.push_back(1);
        res.push_back(temp);
        
        t = temp;
        temp.clear();
        
        // Print first n rows of this pascal triangle
        
        // Indexing starts from 0
        for(int i=1; i<n; i++) {
            
            temp.push_back(1);
            
            // in ith row, we have (i + 1) elements
            // Make from prev row t
            
            for(int k=1; k<t.size(); k++) {
                temp.push_back(t[k] + t[k-1]);
            }
            
            temp.push_back(1);
            
            res.push_back(temp);
            t = temp;
            
            temp.clear();
        }        
        
        return res;
    }
};