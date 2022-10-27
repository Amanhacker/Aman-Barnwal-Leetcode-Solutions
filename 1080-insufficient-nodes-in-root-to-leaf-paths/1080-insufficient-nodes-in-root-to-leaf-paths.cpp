/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
   
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
    
        if(root == NULL)                        return root;
        
        // If root is leaf, we compare the limit and root.val
        
        if(root->left == root->right) {
            if(root->val < limit)               return NULL;
            else                                return root;
        }
        
        // If root has ledt children
        if(root->left != NULL) {             
            root->left = sufficientSubset(root->left, limit - root->val);
        }
        
        // If root has right children
        if(root->right != NULL) {
            root->right = sufficientSubset(root->right, limit - root->val);            
        }   
        
        // If a node become a new leaf, it means it has no valid path leading to an original leaf, so we need to remove it.
        
        if(root->left == root->right)       return NULL;
        
        return root;
    }
    
};