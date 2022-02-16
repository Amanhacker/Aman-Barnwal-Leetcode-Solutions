class Solution {
public:
   
    int timeRequiredToBuy(vector<int>& v, int k) {
    
        int time = 0;
        int n = v.size();
        
        while(v[k] > 0) {

            // Decrease each element of array by 1
            
            for(int i=0; i<n && v[k] > 0; i++) {
                
                if(v[i] > 0) {
                    v[i]--;
                    time++;
                }
            }
        }
        
        return time;
    }
    
};