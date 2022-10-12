class Solution {
public:
    
    int numTrees(int n) {
    
        // We have to find the no of structurally unique BSTs which has exactly n nodes of unique values from [1, n]
        
        // For each i in [1, n], consider each i as root node
        
        // Let's say, the left child of root node i will give us total c1 unique BST, 
        // and right child gives c2 unique BST.
        
        // So, the total no of unique BSTs considering node i as root is c1 * c2
        
        // If n = 4 i.e [1, 2, 3, 4]
        // No of unique BSTs = c0 * c3 + c1 * c2 + c2 * c1 + c3 * c0
        
        // I.e We just need to calculate catalan number
        // Cn = for i in [0, n]         C(i) * C(n - i - 1)
        
        vector<int> cat(n + 1, 0);
        
        cat[0] = 1;
        cat[1] = 1;
        
        if(n <= 1)                      return cat[n];
        
        for(int i=2; i<=n; i++) {
            
            cat[i] = 0;             
            
            for(int j=0; j<i; j++)      cat[i] += cat[j] * cat[i - j - 1];
        }
        
        return cat[n];
    }
    
};