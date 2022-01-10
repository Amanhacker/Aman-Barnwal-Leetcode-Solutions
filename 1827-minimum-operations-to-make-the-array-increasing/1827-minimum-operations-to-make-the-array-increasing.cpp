class Solution {
public:
    
    int minOperations(vector<int>& v) {
    
        int count = 0;
        int n = v.size();
        
        if(n <= 1)                                          return 0;
        
        int temp = v[0];
        
        for(int i=1; i<n; i++) {
            
            if(temp >= v[i]) {
                count += (temp - v[i]) + 1;                
                temp++;
            }   
            
            else                                            temp = v[i];
        }
        
        return count;
    }
    
};    