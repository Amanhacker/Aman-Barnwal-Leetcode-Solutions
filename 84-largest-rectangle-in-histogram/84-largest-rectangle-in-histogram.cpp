class Solution {
public:
    
    int largestRectangleArea(vector<int>& h) {
    
        int maxArea = INT_MIN;
        
        int n = h.size();
        
        // Find the index of Nearest Smallest Left anf Nearest Smallest Right for every index respectively
        // then Width of rectangle = (nsr - nsl - 1), then area = a[i] * (w[i])
        
        
        stack<pair<int, int>> w;
        
        vector<int> nsl, nsr;
        
        // For index of nearest smallest left
        for(int i=0; i<n; i++) {
            
            if(w.empty() == true)                                       nsl.push_back(-1);
            else if(w.top().first < h[i])                               nsl.push_back(w.top().second);
            else if(w.top().first >= h[i]) {
                
                // Pop all elements greater or equal to h[i]
                while(w.empty() == false && w.top().first >= h[i])      w.pop();
                
                // The top of stack contains the 1st element smaller than h[i]
                
                if(w.empty() == true)                                   nsl.push_back(-1);
                else                                                    nsl.push_back(w.top().second);
            }
            
            w.push({h[i], i});
        }
        
        while(w.empty() == false)                                       w.pop();
        
         
        // For index of nearest smallest right
        for(int i=n-1; i>=0; i--) {
            
            if(w.empty() == true)                                     nsr.push_back(-1);
            else if(w.top().first < h[i])                             nsr.push_back(w.top().second);
            else if(w.top().first >= h[i]) {
                
                 // Pop all elements greater or equal to h[i]
                while(w.empty() == false && w.top().first >= h[i])    w.pop();
                
                // The top of stack contains the 1st element smaller than h[i]
                
                if(w.empty() == true)                                 nsr.push_back(-1);
                else                                                  nsr.push_back(w.top().second);
            }
            
            w.push({h[i], i});
        }
        
        reverse(nsr.begin(), nsr.end());
        
//         for(auto &x : nsl)          cout << x << " ";
//         cout << endl;
        
//         for(auto &x : nsr)          cout << x << " ";
//         cout << endl;
        
        for(int i=0; i<n; i++) {
            
            int temp_width;
            
            if(nsr[i] != -1 && nsl[i] != -1)                    temp_width = nsr[i] - nsl[i] - 1;
            
            else if(nsr[i] == -1) {
                // No NSR i.e from ( (nsl[i] + 1) to i ) and from ( (i + 1) to (n - 1) )
                temp_width = (n - 1 - i - 1 + 1) + (i - nsl[i] - 1 + 1);
            }
            
            else if(nsl[i] == -1)  {
                // No nsl i.e from 0 to (i - 1) and i to (nsr - 1)
                temp_width = (i - 1 + 1) + (nsr[i] - 1 - i + 1);
            }
            
            else                                                temp_width = n;
            
            maxArea = max(maxArea, temp_width * h[i]);
        }
        
        
        return maxArea;
    }
    
};