class Solution {
public:
   
    int countElements(vector<int>& a) {
    
        int res = 0;
        int n = a.size();
        
        map<int, int> u;
        
        for(int i=0; i<n; i++)                  u[a[i]]++;
        
        for(auto &x : u) {
            
            int ele = x.first + 1;
            int ct = count(a.begin(), a.end(), ele);
            
            if(ct == 0)                         continue;
            else if(ct >= 1)                    res += x.second;
        }
        
        return res;
    }
    
};