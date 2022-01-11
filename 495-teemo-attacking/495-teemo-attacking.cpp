class Solution {
public:
    
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    
        int time = 0;
        int n = timeSeries.size();
        
        if(n == 0)                                      return 0;
        
        int total = 0;
        
        for(int i=0; i<n-1; i++)                        total += min(timeSeries[i+1] - timeSeries[i], duration);
        
        time = total + duration;
        return time;
    }
    
};