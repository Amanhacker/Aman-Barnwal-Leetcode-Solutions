//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    
    int knapsackHelper(vector<int> a, int n, int target) {
    
        // Using DP
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    
        // Base Condition
        for(int i=0; i<=n; i++)                     dp[i][0] = 1;
        for(int j=1; j<=target; j++)                dp[0][j] = 0;
    
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=target; j++) {
    
                if(a[i-1] <= j)                     dp[i][j] = max(dp[i-1][j-a[i-1]], dp[i-1][j]);
                else                                dp[i][j] = dp[i-1][j];
            }
        }
    
        return dp[n][target];
    }
    
    bool isSubsetSum(vector<int> a, int target){
        
        int n = a.size();
        return knapsackHelper(a, n, target);
    }
    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends