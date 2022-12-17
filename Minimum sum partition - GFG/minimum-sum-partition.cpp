//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	
    int knapsack(int a[], int n, int target) {

        // Using DP
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, 0));

        // Base Condition
        for(int i=0; i<=n; i++)                     dp[i][0] = 1;
        for(int j=1; j<=target; j++)                dp[0][j] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=target; j++) {

                if(a[i-1] <= j)                     dp[i][j] = max(dp[i-1][j-a[i-1]], dp[i-1][j]);
                else                                dp[i][j] = dp[i-1][j];
            }
        }

        for(int j=target/2; j>=0; j--) {
            if(dp[n][j] == 1)                       return target - 2 * j;
        }
        
        return -1;
    }
    
	int minDifference(int a[], int n)  { 
	    
        int sum = 0;

        if(n <= 0)                              return 0;

        for(int i=0; i<n; i++)                  sum += a[i];

        // s1 + s2 = sum
        // s2 - s1 = min

        // Assuming s2 > s1

        // s1 + s1 + min = range
        // min = range - 2s1

        // range - 2*s1 > 0
        // s1 < range / 2

        // For min value of "min", sum should be maximum 
        
        return knapsack(a, n, sum);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends