//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	
	int minDifference(int a[], int n)  { 
	    
	    // Non-negative numbers
	    
	    // Divide the array into 2 sets - S1, S2 such that abs(s1 - s2) = min
	    
	    // Assume, s1 > s2
	    
	    // s1 + s2 = Range
	    // s1 - s2 = diff
	    
	    // s1 = (sum + diff) / 2
	    
	    // s1 - (sum - s1) = diff
	    // 2 * s1 - Range = diff
	    
	    // Range - s2 - s2 = diff
	    // Range - 2*s2 = diff
	    
	    // Range - 2*s2 > 0
	    // s2 < Range / 2
	       
	   int sum = 0;
	   for(int i=0; i<n; i++)               sum += a[i];
	   
	   vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
	   
	   for(int i=0; i<=n; i++)              dp[i][0] = 1;
	   for(int j=1; j<=sum; j++)            dp[0][j] = 0;
	   
	   for(int i=1; i<=n; i++) {
	       for(int j=1; j<=sum; j++) {
	           if(a[i-1] <= j)              dp[i][j] = max(dp[i-1][j-a[i-1]], dp[i-1][j]);
	           else                         dp[i][j] = dp[i-1][j];
	       }
	   }
	   
	   for(int j=sum/2; j>=0; j--) {
	       if(dp[n][j] == 1) {
	           return (sum - 2*j);
	       }
	   }   
	
	   return -1;
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