class Solution {
public:
    
    vector<int> minOperations(string boxes) {
    
        vector<int> res;
        int n = boxes.length();
        
        vector<int> left(n), right(n);
        
        left[0] = 0;
        right[n-1] = 0;
        
        int noOfBalls = 0;
        
        for(int i=1; i<n; i++) {
            if(boxes[i-1] == '1')                               noOfBalls++;
            left[i] = left[i-1] + noOfBalls;
        }
        
        noOfBalls = 0;
        
        for(int i=n-2; i>=0; i--) {
            if(boxes[i+1] == '1')                               noOfBalls++;
            right[i] = right[i+1] + noOfBalls;
        }
        
        for(int i=0; i<n; i++)                                  res.push_back(left[i] + right[i]);
        return res;
    }
    
};