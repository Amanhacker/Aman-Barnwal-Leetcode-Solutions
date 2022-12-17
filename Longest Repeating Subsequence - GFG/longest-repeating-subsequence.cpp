//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
        		
        		
        int findLengthofLRS(string s1, string s2, int n, int m){
        
            vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        
            for(int i=0; i<=n; i++)                      dp[i][0] = 0;
            for(int j=0; j<=m; j++)                      dp[0][j] = 0;
        
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
        
                    if(s1[i-1] == s2[j-1] && i != j)      dp[i][j] = 1 + dp[i-1][j-1];
                    else                                  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        
            return dp[n][m];
        }
		
		int LongestRepeatingSubsequence(string s){
		
		    int n = s.length();
		    return findLengthofLRS(s, s, n, n);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends