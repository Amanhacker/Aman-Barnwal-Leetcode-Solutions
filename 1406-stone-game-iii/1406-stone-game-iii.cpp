class Solution {
public:
    
    // Calculate maximum score made by Alice
    
    int findMaxScoreAlice(int n, vector<int> &piles, int i, vector<int> &dp) {
        
        // Base Condition
        if(i >= n)                                          return 0;
        if(dp[i] != -1)                                     return dp[i];
        
        int ans = INT_MIN, sumAlice = 0;
        
        
        // Alice can take upto 3 stones
        for(int j=i; j<min(n, i + 3); j++) {
            
            sumAlice += piles[j];
            
            // After alice takes, Bob will take 1,2,3 and leave the minimum for Alice
            ans = max(ans, sumAlice + min({ findMaxScoreAlice(n, piles, j+2, dp), findMaxScoreAlice(n, piles, j+3, dp),                                                                 findMaxScoreAlice(n, piles, j+4, dp) }) );
        }
        
        dp[i] = ans;
        return ans;
    }
    
    string stoneGameIII(vector<int>& piles) {
        
        int n = piles.size();
        
        // dp[i] denotes the maximum score if Alice takes the ith stone
        vector<int> dp;
        dp.resize(n + 1, -1);
        
        int sum = accumulate(piles.begin(), piles.end(), 0);
        
        // Find the maximum score made by Alice in the best case
        int aliceScore = findMaxScoreAlice(n, piles, 0, dp);
        int bobScore = sum - aliceScore;
        
        string res = "";
        int diff = aliceScore - bobScore;
        
        if(diff > 0)                               res = "Alice";
        else if(diff < 0)                          res = "Bob";
        else                                       res = "Tie";
        
        return res;
    }
    
    
};