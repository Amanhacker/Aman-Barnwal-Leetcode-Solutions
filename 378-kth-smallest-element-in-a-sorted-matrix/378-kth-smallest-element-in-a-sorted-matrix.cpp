class Solution {
public:
    
    // Using Binary Search
    int kthSmallest(vector<vector<int>>& mat, int k) {
    
        int n = mat.size();
        
        int low = mat[0][0];
        int high = mat[n-1][n-1] + 1;
        
        while(low < high) {
            
            int mid = low + (high - low) / 2;
            
            int ind = n - 1;            // jth index
            int count = 0;
            
			// For each row, we count the elements that are smaller than mid
            
            for(int i=0; i<n; i++) {
                
                while(ind >= 0 && mat[i][ind] > mid)                        ind--;
                count += ind + 1;
            }
            
            if(count < k)                                                   low = mid + 1;
            else                                                            high = mid;
        }
        
        return low;
    }
    
};