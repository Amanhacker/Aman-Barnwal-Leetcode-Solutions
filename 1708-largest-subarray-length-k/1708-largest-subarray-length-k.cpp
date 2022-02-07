class Solution {
public:
    
    vector<int> largestSubarray(vector<int>& a, int k) {
    
        vector<int> res;
        
        // Find all subarrays of length k, and find the largest subarray
        
        int n = a.size();
        
        // Find the largest element in the range [0, n-k]
        auto it = max_element(a.begin(), a.begin() + n - k + 1);
        int index = it - a.begin();
        
        int ele = *it;
        
        // Now, the required subarray is from [index, index + k - 1]
        for(int i=index; i<=index + k - 1; i++)                             res.push_back(a[i]);
        
        return res;
    }
    
};