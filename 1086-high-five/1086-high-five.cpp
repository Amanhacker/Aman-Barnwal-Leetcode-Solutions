class Solution {
public:
    
    
    vector<vector<int>> highFive(vector<vector<int>>& a) {
    
        vector<vector<int>> res;        
        
        int n = a.size();
        unordered_map<int, vector<int>> u;
        
        for(auto &x : a) {
            
            vector<int> temp = x;
            u[temp[0]].push_back(temp[1]);
        }
        
        for(auto &x : u) {
            
            vector<int> t = x.second;
            sort(t.begin(), t.end(), greater<int>());
            
            int sum = 0;
            for(int i=0; i<5; i++)                          sum += t[i];

            vector<int> path;
            
            path.push_back(x.first);
            path.push_back(sum / 5);
            
            res.push_back(path);
            path.clear();
        }
        
        sort(res.begin(), res.end());
        return res;
    }
    
};