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
   
    double mini = DBL_MAX;
    
    void inorder(TreeNode* root, double target, int &res) {
        
        if(root == NULL)                                            return;
        
        inorder(root->left, target, res);
        
        if(abs(target - root->val) <= mini) {
            mini = abs(target - root->val);
            res = root->val;
        }
        
        inorder(root->right, target, res);
        
        return;
    }
    
    int closestValue(TreeNode* root, double target) {
    
        if(root == NULL)                                            return 0;
        
        int res;
        
        // inorder of a BST gives us sorted array
        
        inorder(root, target, res);
        return res;
    }
    
};