class Solution {
public:
  
    int n;
    vector<int> sum;
    
    Solution(vector<int>& w) {
        
        n = w.size();
        
        for(int i=1; i<n; i++)                    w[i] += w[i-1];
        sum = w;
    }
    
    
    int pickIndex() {
        
        int res;
        
        int index = rand() % sum.back();
        
        res = upper_bound(sum.begin(), sum.end(), index) - sum.begin();
        return res;
    }
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */