class Solution {
public:
    
    bool validWordSquare(vector<string>& words) {
    
        int n = words.size();
        int m = INT_MIN;
        
        for(auto &x : words)                                          m = max(m, (int)(x.length()));
        
        vector<vector<char>> mat;
        mat.resize(n, vector<char>(m, '0'));
        
        for(int i=0; i<n; i++) {
            string temp = words[i];
            for(int j=0; j<temp.length(); j++)                          mat[i][j] = temp[j];
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        // Check whether the traverse of matrix is same as that of matrix
        vector<string> res;
        
        for(int j=0; j<m; j++) {
            
            string t = "";
            for(int i=0; i<n; i++) {
                if(mat[i][j] != '0')                                    t += mat[i][j];    
            }   
            
            res.push_back(t);
        }
        
        return (res  == words);
    }
    
};