//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    
    int knapsack(vector<int> &a, int n, int sum) {

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        for(int i=0; i<=n; i++)                 dp[i][0] = 1;
        for(int j=1; j<=sum; j++)               dp[0][j] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=sum; j++) {

                if(a[i-1] == 0)                 dp[i][j] = dp[i-1][j];
                else if(a[i-1] <= j)            dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
                else                            dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][sum];
    }
    
    int findTargetSumWays(vector<int>&a, int target) {
        
        int n = a.size();

        int sum = 0, countZeroes = 0;

        for(auto &x : a) {
            if(x == 0)                                 countZeroes++;
            sum += x;
        }   

        if(target > sum || target < -sum)              return 0;
        if( (target + sum) % 2 != 0 )                  return 0;

        // s1 + s2 = sum
        // s1 - s2 = target

        // s1 = (sum + target) / 2

        int subsetSumReq = (sum + target) / 2;

        int res = knapsack(a, n, subsetSumReq);
        return (1 << countZeroes) * res;
    
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends