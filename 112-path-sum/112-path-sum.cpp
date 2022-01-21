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
    
    void hasHelperPathSum(TreeNode* root, int tar, int sum) {
        
        if(root == NULL)                                       return;
        
        sum += root->val;
        
        // Base Condition
        if(root->left == NULL && root->right == NULL) {
            if(sum == tar) {
                flag = true;
                return;
            }          
        }
        
        if(root->left != NULL)                  hasHelperPathSum(root->left, tar, sum);
        if(root->right != NULL)                 hasHelperPathSum(root->right, tar, sum);
        
        return;
    }
    
    bool hasPathSum(TreeNode* root, int tar) {
    
        if(root == NULL)                                        return false;
        
        hasHelperPathSum(root, tar, 0);
        return flag;
    }
    
};