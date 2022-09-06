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
    
    TreeNode* invertTreeHelper(TreeNode* &root) {
        
        if(root == NULL)                        return root;
        
        // Change left and right subtree interchangeably
        swap(root->left, root->right);
        
        invertTreeHelper(root->left);
        invertTreeHelper(root->right);
        
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
    
        if(root == NULL)                        return root;
        
        // Invert the binary tree
        
        invertTreeHelper(root);
        return root;
    }
    
};