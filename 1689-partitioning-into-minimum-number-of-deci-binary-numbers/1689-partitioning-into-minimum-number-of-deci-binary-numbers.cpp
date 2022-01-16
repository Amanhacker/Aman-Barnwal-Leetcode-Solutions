class Solution {
public:
    
    int minPartitions(string n) {
    
        int res = INT_MIN;
        
        for(auto &x : n) {
            int temp = (int)(x - '0');
            res = max(res, temp);
        }
        
        return res;
    }
    
};