class Solution {
public:
    
    int thirdMax(vector<int>& v) {
    
        long long int max1 = LONG_MIN;
        long long int max2 = LONG_MIN;
        long long int max3 = LONG_MIN;
        
        bool flag = false;
        int n = v.size();
        
        for(int i=0; i<n; i++) {
            
            if(v[i] == INT_MIN)                         flag = true;
            
            if(v[i] > max1) {
                
                max3 = max2;
                max2 = max1;
                max1 = v[i];
            }
            
            else if(v[i] > max2 && v[i] != max1) {
                max3 = max2;
                max2 = v[i];
            }
            
            else if(v[i] > max3 && v[i] != max1 && v[i] != max2) {
                max3 = v[i];
            }   
        }
       
        if(max3 == LONG_MIN)                             return max1;
        else                                             return max3;
    }
    
};