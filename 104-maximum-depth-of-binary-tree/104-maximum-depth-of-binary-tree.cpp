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

    int height(TreeNode* root) {
        
        if(root == NULL)                    return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return 1 + max(left, right);
        
    }
    
    int maxDepth(TreeNode* root) {
    
        int h = 0;
        
        if(root == NULL)                            return h;
        
        h = height(root);
        return h;
    }
    
};