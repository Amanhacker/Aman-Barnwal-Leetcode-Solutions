class Solution {
public:
    
    vector<vector<string>> groupStrings(vector<string>& v) {
    
        vector<vector<string>> res;
        
        int n = v.size();
        
        unordered_map<string, vector<string>> u;
        
        for(int i=0; i<n; i++) {
            
            string temp = v[i];

            string order = "";
            cout << temp << " ";
            
            for(int j=1; j<temp.size(); j++) {
                
                
                int diff = (int)(temp[j] - 'a') % 26 - (int)(temp[j-1] - 'a') % 26;
                
                // if(diff > 26)                               diff = diff - 26;
                if(diff <= 0)                          diff = diff + 26;
                
                
                int mini = min(diff, 26 - diff);
                int maxi = max(diff, 26 - diff);
                
                cout << diff << " " << mini << " " << maxi << " ";
                // order += to_string(mini) + "-" + to_string(maxi) + "-";    
                order += to_string(diff) + "-";
            }
            
            cout << temp << " " << order << endl;
            u[order].push_back(temp);
        }

        vector<string> path;
        
        for(auto &x : u) {
            
            vector<string> t = x.second;
            
            for(auto &x1 : t)                           path.push_back(x1);
            
            res.push_back(path);
            path.clear();
        }
        
        
        return res;
    }
    
};