class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs) {
    
        // Here, If you're travelling today then 3 choices : 1-day, 7-day, or 30-day pass.

        int n = days.size();
        vector<int> dp(366, 0);
        
        // dp(i) = cost to fulfill your travel plan from day 1 to day i. 
        
        for(int i=1; i<=365; i++) {
            
            // For non-travel days, the cost stays the same as for the previous day. 
            
            if(find(days.begin(), days.end(), i) == days.end())              dp[i] = dp[i-1];
            
            // For travel days, it's a minimum of yesterday's cost plus single-day ticket, 
            // or cost for 8 days ago plus 7-day pass, or cost 31 days ago plus 30-day pass.
            
            else {
                dp[i] = min({dp[max(0, i - 1)] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]}); 
            }   
        }
        
        return dp[365];
    }
    
};