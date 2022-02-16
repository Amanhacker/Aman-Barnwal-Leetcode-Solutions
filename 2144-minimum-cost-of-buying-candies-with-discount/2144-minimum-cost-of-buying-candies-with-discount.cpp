class Solution {
public:
    
    int minimumCost(vector<int>& cost) {
    
        int res = 0;
        int n = cost.size();
        
        sort(cost.begin(), cost.end());
        
        for(int i=n-1; i>=0; ) {
            
            // Add the cost[i], and cost[i-1], and give the cost[i-2] for free
            res += cost[i];
            
            i--;
            
            if(i >= 0)                              res += cost[i];
            
            i--;
            
            // Give 3rd candy for free
            if(i >= 0)                              i--;
        }
        
        return res;
    }
    
};