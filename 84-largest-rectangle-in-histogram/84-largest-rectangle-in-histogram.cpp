class Solution {
public:
    
    int largestRectangleArea(vector<int>& a) {
    
        int area = INT_MIN;
        int n = a.size();

        // Find NGL and NGR at each index, and width = ngr - ngl - 1

        stack<pair<int, int>> w;                // 1st element : value, 2nd element : index
        vector<int> nsl, nsr;

        // Finding Next Smaller Left index

        for(int i=0; i<n; i++) {

            if(w.empty() == true)                       nsl.push_back(-1);
            else if(w.top().first < a[i])               nsl.push_back(w.top().second);
            else if(w.top().first >= a[i]) {

                while(w.empty() == false && w.top().first >= a[i])        w.pop();

                if(w.empty() == true)                   nsl.push_back(-1);
                else                                    nsl.push_back(w.top().second);
            }

            w.push({a[i], i});
        }

        for(auto &x : nsl)                              cout << x << " ";
        // cout << endl;

        while(w.empty() == false)                       w.pop();

        // Finding Next Smaller Right
        for(int i=n-1; i>=0; i--) {

            if(w.empty() == true)                       nsr.push_back(-1);
            else if(w.top().first < a[i])               nsr.push_back(w.top().second);
            else if(w.top().first >= a[i]) {

                while(w.empty() == false && w.top().first >= a[i])        w.pop();

                if(w.empty() == true)                   nsr.push_back(-1);
                else                                    nsr.push_back(w.top().second);
            }

            w.push({a[i], i});
        }

        reverse(nsr.begin(), nsr.end());

        // for(auto &x : nsr)                              cout << x << " ";
        // cout << endl;

        int temp;
        int width = INT_MIN;

        // For each index, find the width
        for(int i=0; i<n; i++) {

            if(nsl[i] == -1 && nsr[i] == -1) {
                    temp = n;
            }   
            
            // No NSL, i.e from [0, i-1], and from [i, nsr[i]-1]
            else if(nsl[i] == -1) {
                temp = i + (nsr[i] - 1 - i + 1);                // nsr[i] 
            }
            
            // No NSR, i.e [nsl[i]+1, i], and from [i+1, n-1]
            else if(nsr[i] == -1) {
                temp = i - (nsl[i] + 1) + 1 + (n-1) - (i+1) + 1;        
            }
            
            else {
                temp = nsr[i]- nsl[i] - 1;                 
            }   

            area = max(area, temp * a[i]);
            // cout << temp << " ";
        }
        
        return area;    
    }
    
};