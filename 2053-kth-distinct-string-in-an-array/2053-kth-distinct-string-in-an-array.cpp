class Solution {
public:
    
    string kthDistinct(vector<string>& v, int k) {
    
        string res = "";
        
        // d contains distinct string in the same order         // 1st arg - index, 2nd arg - string
        vector<pair<int, string>> d; 
        int n = v.size();
        
        unordered_map<string, pair<int, int>> u;               // 1st arg - string, 2nd arg - index, 3rd arg - freq
        
        for(int i=0; i<n; i++) {            
            u[v[i]].second++;
            u[v[i]].first = i;
        }
        
        for(auto &x : u) {
            if(x.second.second == 1)                            d.push_back({x.second.first, x.first});
        }
        
        sort(d.begin(), d.end());
        if(d.size() < k)                                        return res;
        
        res = d[k-1].second;
        return res;
    }
    
};