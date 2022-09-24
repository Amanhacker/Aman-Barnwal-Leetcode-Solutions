class Solution {
public:

    int findArea(vector<int> &h, int m) {

        int maxWidth = INT_MIN;
        int n = m;

        // Find the NSL and NSR of this vector
        stack<pair<int, int>> w;                    // 1st element - value, 2nd element - index
        while(w.empty() == false)                   w.pop();

        vector<int> nsl, nsr;
        
        nsl.clear();
        nsr.clear();

        while(w.empty() == false)                   w.pop();

        // For NSL
        for(int i=0; i<m; i++) {

            if(w.empty() == true)                   nsl.push_back(-1);
            else if(w.top().first < h[i])           nsl.push_back(w.top().second);
            else if(w.top().first >= h[i]) {

                while(w.empty() == false && w.top().first >= h[i])              w.pop();

                if(w.empty() == true)               nsl.push_back(-1);
                else                                nsl.push_back(w.top().second);
            }

            w.push({h[i], i});
        }

        while(w.empty() == false)                   w.pop();

        // For NSR
        for(int i=m-1; i>=0; i--) {

            if(w.empty() == true)                   nsr.push_back(-1);
            else if(w.top().first < h[i])           nsr.push_back(w.top().second);
            else if(w.top().first >= h[i]) {

                while(w.empty() == false && w.top().first >= h[i])              w.pop();

                if(w.empty() == true)               nsr.push_back(-1);
                else                                nsr.push_back(w.top().second);
            }

            w.push({h[i], i});
        }

        reverse(nsr.begin(), nsr.end());

        int area = INT_MIN;
        
        for(int i=0; i<m; i++) {

            if(nsl[i] == -1 && nsr[i] == -1)            maxWidth = m;
            
            
            // [0, i-1], [i, nsr[i]-1]
            else if(nsl[i] == -1)                       maxWidth = i + (nsr[i] - 1) - i + 1;             
            
             // [nsl[i] + 1, i-1], [i, n-1]
            else if(nsr[i] == -1)                       maxWidth = (i - 1) - (nsl[i] + 1)  + 1 + (n-1) - i + 1;   
            
             // [nsl[i] + 1, nsr[i] - 1]
            else                                        maxWidth = (nsr[i] - 1) - (nsl[i] + 1) + 1;  
            
             area = max(area, maxWidth * h[i]);    
        }
        
        return area;
    }


    int maximalRectangle(vector<vector<char>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int maxArea = INT_MIN;

        // Convert 2D Binary Matrix to 1D Array, and then find the maxArea in each 1D Array
        vector<vector<int>> grid(n, vector<int>(m));

        for(int j=0; j<m; j++) {
            if(mat[0][j] == '0')                                grid[0][j] = 0;
            else                                                grid[0][j] = 1;
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == '1')                            grid[i][j] += grid[i-1][j] + (mat[i][j] - '0');
                else                                            grid[i][j] = 0;
            }
        }
        
//         for(int i=0; i<n; i++) {
//            for(int j=0; j<m; j++) {
//                cout << grid[i][j] << " ";      
//            }
//             cout << endl;
//         }
        
//         cout << endl;
        
        // Now, we have n 1D Histogram

        for(int i=0; i<n; i++) {

            // Find the width of this 1D Histogram
            int maxTemp = findArea(grid[i], m);

            // Find the NSL and NGL of this vector
            maxArea = max(maxArea, maxTemp);
        }

        return maxArea;    
    }
    
};