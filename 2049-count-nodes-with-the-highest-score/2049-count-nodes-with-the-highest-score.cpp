class Solution {
public:
    
    class TreeNode {
        
        public :
            
            int nodeCount = 0;
            long score = 0L;
            TreeNode* left, *right;
    };
    
    int countNodes(TreeNode* root) {
        
        if(root == NULL)                            return 0;
        
        // postorder = left -> right -> root
        
        root->nodeCount =  countNodes(root->left) + countNodes(root->right) + 1;
        return root->nodeCount;
    }
    
    int countHighestScoreNodes(vector<int>& parent) {
    
        long maxi = 0;         // Maximum identifiable score in tree
        int n = parent.size();
        
        vector<TreeNode*> tree(n);
        
        // tree[0] = new TreeNode();
        
        for(int i=0; i<n; i++) {
            tree[i] = new TreeNode();
        }
        
        // Build the tree
        for(int i=0; i<n; i++) {
            
            int par = parent[i];
            
            if(par != -1) {
                if(tree[par]->left == NULL)             tree[par]->left = tree[i];
                else                                    tree[par]->right = tree[i];
            }
        }
        
        // Find the size of subtree of each node
        countNodes(tree[0]);
        
        // To find the score of each node
        
        for(int i=0; i<n; i++) {
            
            // Removing node i
            long pdt = 1;
            
            int leftCount, rightCount, parCount;
            
            if(tree[i]->left == NULL)          leftCount = 0;
            else                               leftCount = tree[i]->left->nodeCount;
            
            if(tree[i]->right == NULL)         rightCount = 0;
            else                               rightCount = tree[i]->right->nodeCount;
            
            parCount = n - leftCount - rightCount - 1;
            
            if(leftCount > 0)                      pdt *= leftCount;
            if(rightCount > 0)                     pdt *= rightCount;
            if(parCount > 0)                       pdt *= parCount;
            
            tree[i]->score = pdt;
            maxi = max(maxi, pdt);
        }
        
        int ans = 0;
        
        // Count no of nodes having score maxi
        
        for(int i=0; i<n; i++) {
            if(tree[i]->score == maxi)              ans++;
        }
        
        return ans;
    }
    
};