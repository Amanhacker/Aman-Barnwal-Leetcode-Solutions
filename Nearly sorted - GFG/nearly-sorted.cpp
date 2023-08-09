//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    
    vector<int> nearlySorted(int a[], int n, int k){
        
        vector<int> res;
        
        // Min Heap using priority queue
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<n; i++) {
            
            pq.push(a[i]);
            
            if(pq.size() > k) {
                res.push_back(pq.top());
                pq.pop();
            }
            
        }
        
        while(pq.empty() == false) {
            res.push_back(pq.top());
            pq.pop();
        }
        
        return res;
    }
    
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends