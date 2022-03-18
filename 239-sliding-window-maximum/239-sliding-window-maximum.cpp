class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        
        vector<int> res;
        int n = a.size();
        
        int i = 0, j = 0;
        deque<int> maxi;
        
        // Here we are using the sliding window and storing the max into the deque. 
        
        // As we slide the window, the first element of window may be included in our calc so to revert that and get the next max of window we are storing all the elem to our max and all elem to left of our max are of no use
        
        // Here, pop_front means removing the 1st element, and pop_back means removing the last element of deque
        
        while(j < n) {
                
            // Pop all the elements smaller than a[j]
            while(maxi.empty() == false && maxi.back() < a[j]) {            // Back means last element of vector
                maxi.pop_back();
            }

            // Then push a[j] into vector maxi
            maxi.push_back(a[j]);
            
            if(j - i + 1 < k) {
                j++;
            }
            
            else if(j - i + 1 == k) {
                
                // Maximum value in this window is front i.e first element of vector maxi
                res.push_back(maxi.front());
                
                // For the next window, we need to remove front i.e first element of maxi vector
                if(a[i] == maxi.front()) {
                    maxi.pop_front();
                    // maxi.erase(maxi.begin());
                }
                
                // Slide the window
                
                i++;
                j++;
            }
        }
        
        return res;
    }
};