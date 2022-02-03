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
        
        int llv = 1;                    // Start node value at each level
        int curVal = 0;                 // Last node value at cur level
        
        int n = label;
        
        while(curVal < n) {
            curVal += llv;    // Last node value is no.of nodes at present lev added to last node value at prev lev
            llv *= 2;         // No.of nodes at a level is doubled than that of no.of nodes at prev level
        }
        
        // We have to divide by 2, because it adds extra no.of nodes at one level
        llv /= 2;
        
        
        // Now, llv becomes start value node at last level of BT
        
        // We start with the last level
        while(n != 1) {
            
            res.push_back(n);
            
            // Find the node which needs to be swapped with this n
            int complementNode = (3 * llv) - 1 - n;
            
            // Update node at each step, because we are moving one level upwards in each step
            n = complementNode / 2;
            
            llv /= 2;                       // We are moving one level upwards in each step
        }
        
        res.push_back(1);
        
        // Reverse the vector, since we started with leaf node
        reverse(res.begin(), res.end());
        
        // Now, res is the resultant path
        return res;
    }
    
};