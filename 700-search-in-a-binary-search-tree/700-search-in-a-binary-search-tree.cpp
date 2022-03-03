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

    void inorder(TreeNode* root, int val, TreeNode* &res, bool &flag) {
        
        if(root == NULL || flag == true)                               return;
        
        inorder(root->left, val, res, flag);
        
        if(root->val == val) {
            
            res = root;
            flag = true;
            
            return;
        }
        
        inorder(root->right, val, res, flag);
        
        return;
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
    
        TreeNode* res = NULL;
        
        bool flag = false;
        inorder(root, val, res, flag);
        
        return res;
    }
    
};