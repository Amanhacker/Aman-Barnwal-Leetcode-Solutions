class Solution {
public:
    
    vector<int> lexicalOrder(int n) {
    
        vector<int> res;
        vector<string> v;
        
        for(int i=1; i<=n; i++)                 v.push_back(to_string(i));
        sort(v.begin(), v.end());
        
        for(auto &x : v)                        res.push_back(stoi(x));
        return res;
    }
    
};