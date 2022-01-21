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
        
        if(root == NULL)                            return 0;
        
        int l = height(root->left);
        int r = height(root->right);
        
        return 1 + max(l, r);
    }
    
    void findLastLevel(TreeNode* root, int lev, int &sum) {
        
        if(root == NULL)                            return;
        
        if(lev == 1) {
            sum += root->val;
        }
        else if(lev > 1) {
            if(root->left != NULL)                  findLastLevel(root->left, lev - 1, sum);
            if(root->right != NULL)                 findLastLevel(root->right, lev - 1, sum);
        }
        
        return;
    }
    
    int deepestLeavesSum(TreeNode* root) {
    
        if(root == NULL)                                            return 0;
        
        // Using level order traversal
        int h = height(root);
        
        int sum = 0;
        findLastLevel(root, h, sum);
        
        return sum;
    }
    
};