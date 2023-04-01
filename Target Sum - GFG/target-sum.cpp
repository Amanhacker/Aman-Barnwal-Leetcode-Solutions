//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    
    int findTargetSumWays(vector<int>&a, int target) {
        
        int n = a.size();
        
        // Assign '+' or '-' sign before an element of array
        
        // s1 + s2 = sum
        // s1 - s2 = target
        int sum = 0;
        
        for(int i=0; i<n; i++)                  sum += a[i];
        
        // s1 = (sum + target) / 2
        
         if(n == 0 || n == 1)                  return (sum == abs(target)) ? 1 : 0;
        
        if( (sum + target) % 2 != 0 || sum < abs(target) ){
            return 0;
        }
        
        int s = (sum + target) / 2;
        
        vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
        
        for(int i=0; i<=n; i++)                 dp[i][0] = 1;
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=s; j++) {
                if(a[i-1] <= j)                 dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
                else if(a[i-1] > j)             dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][s];
    
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