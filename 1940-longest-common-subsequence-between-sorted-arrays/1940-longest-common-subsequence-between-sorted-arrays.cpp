class Solution {
public:
    
    vector<int> longestCommonSubsequence(vector<vector<int>>& a) {
    
        vector<int> res;
        int n = a.size();
        
        if(n == 0)                                              return res;
        if(n == 1)                                              return a[0];
        
        // Here, all the given arrays are in strictly ascending order, i.e the arrays have no duplicates
        
        vector<int> count(101);

        for(auto &x : a) {
            
            vector<int> temp = x;
            
            for(int i=0; i<temp.size(); i++) {
                
                count[temp[i]]++;
                
                if(count[temp[i]] == n)                         res.push_back(temp[i]);
            }
        }
        
        return res;
    }
    
};