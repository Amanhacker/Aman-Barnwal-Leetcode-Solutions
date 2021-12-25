class Solution {
public:
    
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
    
        int cost = 0;
        
        // All shortest path from robot to home have the same cost
        
        int x_min = min(startPos[0], homePos[0]);
        int x_max = max(startPos[0], homePos[0]);
                
        int y_min = min(startPos[1], homePos[1]);
        int y_max = max(startPos[1], homePos[1]);
        
        for(int i=x_min; i<=x_max; i++)                                 cost += rowCosts[i];
        for(int j=y_min; j<=y_max; j++)                                 cost += colCosts[j];
        
        cost -= rowCosts[startPos[0]];
        cost -= colCosts[startPos[1]];
        
        return cost;
    }
    
};