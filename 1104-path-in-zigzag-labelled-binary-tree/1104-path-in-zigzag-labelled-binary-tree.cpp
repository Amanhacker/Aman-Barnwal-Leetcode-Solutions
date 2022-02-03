class Solution {
public:
    
    vector<int> pathInZigZagTree(int label) {
    
        vector<int> res;
        
        // For odd numbered level, numbering is from left to right
        // For even numbered level, numbering is from right to left
        
        // Intuition : 
        
            // For normal BT, the parent node of node n is n/2
            // But, for this special BT, the parent node of node n is complementNode / 2

            // end - n = x - start, at one level

            // Let's say, we need to find the complement node of node n
            // x = end + start - n

            // Here, end = 2 * llv - 1
               //    start = llv
               //    So, x = 3 * llv - 1 - n
        
        int llv = 1;
        int curVal = 0;
        
        int n = label;
        
        while(curVal < n) {
            curVal += llv;
            llv *= 2;
        }
        
        llv /= 2;
        
        while(n != 1) {
            
            res.push_back(n);
            
            // Find the node which needs to be swapped with this n
            int complementNode = (3 * llv) - 1 - n;
            n = complementNode / 2;
            
            llv /= 2;
        }
        
        res.push_back(1);
        
        // Reverse the vector, since we started with leaf node
        reverse(res.begin(), res.end());
        
        // Now, res is the resultant path
        return res;
    }
    
};