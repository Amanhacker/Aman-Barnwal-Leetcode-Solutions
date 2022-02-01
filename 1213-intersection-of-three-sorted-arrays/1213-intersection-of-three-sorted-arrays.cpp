class Solution {
public:
    
    vector<int> arraysIntersection(vector<int>& a1, vector<int>& a2, vector<int>& a3) {
    
        vector<int> res;
        
        int i = a1.size() - 1;
        int j = a2.size() - 1;
        int k = a3.size() - 1;
        
        while(i >= 0 && j >= 0 && k >= 0) {
            
           if(a1[i] > a2[j] || a1[i] > a3[k])                              i--;
           else if(a2[j] > a3[k] || a2[j] > a1[i])                         j--;
           else if(a3[k] > a1[i] || a3[k] > a2[j])                         k--;
          
           else {
               
               res.push_back(a1[i]);
               
               i--;
               j--;
               k--;
           }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
};