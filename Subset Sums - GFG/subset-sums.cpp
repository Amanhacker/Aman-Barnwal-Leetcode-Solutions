//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    
    void subsetSumHelper(int ind, int sum, int n, vector<int> &a, vector<int> &res) {
        
        // Base Condition
        if(ind == n) {
            res.push_back(sum);    
            return;
        }
        
        // Pick or non-pick of index "ind"
        
        subsetSumHelper(ind + 1, sum + a[ind], n, a, res);
        subsetSumHelper(ind + 1, sum, n, a, res);
    
        return;
    }
    
    vector<int> subsetSums(vector<int> a, int n) {
        
        vector<int> res;
        int sum = 0;
        
        subsetSumHelper(0, sum, n, a, res);
        
        return res;
    }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends