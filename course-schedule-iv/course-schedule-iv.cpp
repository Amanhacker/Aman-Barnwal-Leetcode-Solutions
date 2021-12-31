class Solution {
public:
    
    // Using Bellmann Ford Algorithm - O(n ^ 3)

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prereq, vector<vector<int>>& queries) {

        vector<bool> res;

        // Use Topological sort in layerwise fashion

        int n = numCourses;

        vector<vector<int>> mat(n, vector<int>(n, INT_MAX/2));

        for(int i=0; i<prereq.size(); i++) {

            int u = prereq[i][0];
            int v = prereq[i][1];

            // Course u needs to be completed before course v i.e u -> v
            mat[u][v] = 1;
        }

        // If, there are no prerequisites, then each course is independent
        if(prereq.size() == 0) {
            res.resize(n, false);
            return res;
        }

        // Using Bellmann Ford Algorithm
        
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    
                    if(mat[i][j] > mat[i][k] + mat[k][j])                   mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
        

        for(int i=0; i<queries.size(); i++) {

            int u = queries[i][0];
            int v = queries[i][1];

            if(mat[u][v] == INT_MAX / 2)                                    res.push_back(false);
            else                                                            res.push_back(true);
        }

        return res;
    }

    
};