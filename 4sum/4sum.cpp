class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& a, int tar) {
    
        vector<vector<int>> res;
        vector<int> path;
        
        int n = a.size();
        sort(a.begin(), a.end());
        
        for(int i=0; i<n-3; i++) {
            for(int j=i+1; j<n-2; j++) {
                
                // Using Two Pointers method
                int start = j + 1, end = n - 1;
                
                while(start < end) {
                    
                    if(a[start] + a[end] == tar - a[i] - a[j]) {
    
                        path.push_back(a[i]);
                        path.push_back(a[j]);
                        path.push_back(a[start]);
                        path.push_back(a[end]);
                            
                        if(find(res.begin(), res.end(), path) == res.end()) {
                            res.push_back(path);
                        }
                        
                        path.clear();

                        start++;
                        end--;
                    }
                    
                    else if(a[start] + a[end] < tar - a[i] - a[j])              start++;
                    else if(a[start] + a[end] > tar - a[i] - a[j])              end--;
                }
                
            }
        }
        
        return res;
    }
    
};