class Solution {
public:
   
    int dietPlanPerformance(vector<int>& cal, int k, int lower, int upper) {
    
        int res = 0;
        
        int n = cal.size();
        int sum = 0;
        
        for(int i=0; i<k; i++)                          sum += cal[i];
        
        if(sum < lower)                                 res--;
        else if(sum > upper)                            res++;
        
        for(int i=k; i<n; i++) {
         
            sum += cal[i] - cal[i-k];
            
            if(sum < lower)                             res--;
            else if(sum > upper)                        res++;
        }
        
        return res;
    }
    
};