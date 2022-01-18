class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs) {
    
        // Here, If you're travelling today then 3 choices : 1-day, 7-day, or 30-day pass.

        int n = days.size();
        vector<int> dp (366, 0);
        
        // dp(i) = cost to fulfill your travel plan from day 1 to day i. 
        
        unordered_set<int> travel;
        for(auto &x : days)                                         travel.insert(x);
        
        for(int i=1; i<=365; i++) {
            
            if(travel.find(i) == travel.end())                      dp[i] = dp[i-1];
            
            else {
                dp[i] = min({dp[max(0, i - 1)] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]}); 
            }   
        }
        
        return dp[365];
    }
    
};