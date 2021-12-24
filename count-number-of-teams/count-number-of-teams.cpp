class Solution {
public:
    
    
    int numTeams(vector<int>& v) {
        
        int count = 0;
        
        // Choose pairs of 3 value such that it is either strictly increasing or strictly decreasing
        
        int n = v.size();
        
        for(int i=0; i<n-1; i++) {
            
            // For strictly ascending order
            
            int leftLess = 0;       // How many elements on the left are less than element at index i
            int rightGreater = 0;   // How many elements on the right are greater than element at index i
            
            // For strictly descending order
            
            int leftGreater = 0;    // How many elements on the left are greater than element at index i
            int rightLess = 0;      // How many elements on the right are less than element at index i
            
            for(int j=i-1; j>=0; j--) {
                if(v[j] < v[i])                 leftLess++;
                else                            leftGreater++;
            }
            
            for(int j=i+1; j<n; j++) {
                if(v[j] > v[i])                 rightGreater++;
                else                            rightLess++;
            }
            
            count += (leftLess * rightGreater) + (leftGreater * rightLess);
        }
        
        return count;
    }
    
};