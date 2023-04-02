//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    const int mod = 1003;
    
    int helper(string s, int i, int j, bool isTrue, vector<vector<vector<long long int>>> &dp) {
        
        // Base Condition
        if(i > j)                               return 0;
        if(dp[i][j][isTrue] != -1)              return dp[i][j][isTrue];
        
        if(i == j) {
            if(isTrue == true)                  return (s[i] == 'T');
            else                                return (s[i] == 'F');
        }
        
        int ans = 0;
        
        // Run for loop for k
        for(int k=i+1; k<=j-1; k += 2) {
            // k is always at  operator
            // (i, k - 1), (k + 1, j)
            
            int lT = helper(s, i, k - 1, true, dp);
            int lF = helper(s, i, k - 1, false, dp);
            
            int rT = helper(s, k + 1, j, true, dp);
            int rF = helper(s, k + 1, j, false, dp);
            
            if(s[k] == '&') {
                if(isTrue == true)          ans += (lT * rT);
                else                        ans += (lT * rF) + (lF * rT) + (lF * rF); 
                
                ans %= mod;
            }
            
            else if(s[k] == '|') {
                if(isTrue == true)          ans += (lT * rT) + (lT * rF) + (lF * rT);
                else                        ans += (lF * rF);
                
                ans %= mod;
            }
            
            else if(s[k] == '^') {
                if(isTrue == true)          ans += (lT * rF) + (lF * rT);
                else                        ans += (lT * rT) + (lF * rF);
                
                ans %= mod;
            }
        }
        
        dp[i][j][isTrue] = ans % mod;
        return ans % mod;
    }

    int countWays(int n, string s){
        
        vector<vector<vector<long long int>>> dp;
        dp.resize(n + 1, vector<vector<long long int>>(n + 1, vector<long long int>(n + 1, -1)));
        
        return helper(s, 0, n - 1, true, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends