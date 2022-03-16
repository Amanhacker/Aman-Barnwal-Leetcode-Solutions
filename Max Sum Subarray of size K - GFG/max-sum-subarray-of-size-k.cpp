// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    
    int maximumSumSubarray(int k, vector<int> &a , int n){
        
        int maxi = INT_MIN;
        int sum = 0;
        
        int i = 0, j = 0;
        
        while(j < n) {
            
            sum += a[j];
            
            // Window size = (j - i + 1)
            
            if(j - i + 1 < k) {
                j++;
            }
            
            else if(j - i + 1 == k) {
                
                maxi = max(maxi, sum);
                
                sum -= a[i];                    // Subtract the leftmost from the window, since we move to right
                
                // Move the sliding window one to the right
                i++;
                j++;
            }
        }
        
        return maxi;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends