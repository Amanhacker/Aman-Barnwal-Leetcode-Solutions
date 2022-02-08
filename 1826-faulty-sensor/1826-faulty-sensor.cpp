class Solution {
public:
    
    int badSensor(vector<int>& a1, vector<int>& a2) {
    
        int res = -1;
        
        int n = a1.size();
        int i = 0;
        
        while(i < n && a1[i] == a2[i])                                          i++;
        
        while(i + 1 < n && a1[i] == a2[i + 1] && a1[i + 1] == a2[i])            i++;
        
        if(i >= n - 1)                                                          res = -1;
        else if(a1[i] == a2[i+1])                                               res = 1;    
        else                                                                    res = 2;

        return res;
    }
    
};