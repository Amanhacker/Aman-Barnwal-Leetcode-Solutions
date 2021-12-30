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
    
    void preorder(TreeNode* root, int v, TreeNode* &res) {
        
        if(root == NULL)                                    return;
        
        if(root->val == v) {
            res = root;
            return;
        }
        
        preorder(root->left, v, res);
        preorder(root->right, v, res);
        
    }    
    
    TreeNode* searchBST(TreeNode* root, int val) {
    
        TreeNode* res = NULL;
        
        if(root == NULL)                                    return NULL;
        
        preorder(root, val, res);
        return res;
    }
    
};