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

    bool flag = false;
    
    void dfs(TreeNode* root, TreeNode* &res, int val) {
        
        if(root == NULL || flag == true)                  return;
        
        if(root->val == val) {
            
            res = root;
            flag = true;
            
            return;
        }
        
        dfs(root->left, res, val);
        dfs(root->right, res, val);
        
        return;
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
    
        TreeNode* res = NULL;
        
        dfs(root, res, val);
        
        return res;
    }
    
};