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

    void findAllPathSum(TreeNode* root, int temp, int sum, bool &flag) {
        
        if(root == NULL)                   return;
        if(flag == true)                   return;
        
        temp += root->val;
        
        // if found a leaf node
        if(root->left == NULL && root->right == NULL && temp == sum) {
            flag = true;
            return;
        }
        
        findAllPathSum(root->left, temp, sum, flag);
        findAllPathSum(root->right, temp, sum, flag);
        
        return;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
    
        if(root == NULL)                    return false;
        
        // Find all the nodes from root to leaf node and then find the sum
        
        bool flag = false;
        findAllPathSum(root, 0, targetSum, flag);
        
        return flag;
    }
    
};