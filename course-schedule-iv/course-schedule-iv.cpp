class Solution {
public:
    
    // Using Bellmann Ford Algorithm - O(n ^ 3)

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prereq, vector<vector<int>>& queries) {

        vector<bool> res;
        int n = numCourses;

        vector<vector<int>> mat(n, vector<int>(n, INT_MAX/2));

        for(int i=0; i<prereq.size(); i++) {
            // Course prereq[i][0] needs to be completed before course prereq[i][1] i.e prereq[i][0] -> prereq[i][1]
            mat[prereq[i][0]][prereq[i][1]] = 1;
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

            if(mat[queries[i][0]][queries[i][1]] == INT_MAX/2)              res.push_back(false);
            else                                                            res.push_back(true);
        }

        return res;
    }

    
};