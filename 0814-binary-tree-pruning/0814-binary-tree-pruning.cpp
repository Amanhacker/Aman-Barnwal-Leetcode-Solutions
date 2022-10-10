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
    
    // Checks whether the subtree contains 1 or not
    // Return true if it contains 1, else return false
    
    // If it does not contain 1. then delete that node
    bool pruneHelper(TreeNode* &root) {
        
        if(root == NULL)                                return false;
        
        // Check if any node in the left and right subtree contains a 1.
        bool leftPruneTree = pruneHelper(root->left);
        bool rightPruneTree = pruneHelper(root->right);
        
        // If the left subtree does not contain a 1, prune the subtree.
        if(leftPruneTree == false)                       root->left = NULL;
        
        // If the right subtree does not contain a 1, prune the subtree.
        if(rightPruneTree == false)                      root->right = NULL;
        
        return (root->val == 1) || leftPruneTree || rightPruneTree;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        if(root == NULL)                        return root;
        
        bool flag = pruneHelper(root);
        
        if(flag == true)                        return root;
        else                                    return NULL;
    }
    
};