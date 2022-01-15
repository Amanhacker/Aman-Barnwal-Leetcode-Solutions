class Solution {
public:
    
    int thirdMax(vector<int>& v) {
    
        vector<int> w;
        
        for(auto &x : v) {
            if(find(w.begin(), w.end(), x) == w.end())          w.push_back(x);
        }                    
        
        int n = w.size();
        sort(w.begin(), w.end());
        
        if(n >= 3)                                              return w[n-3];
        
        return w[n-1];
    }
    
};