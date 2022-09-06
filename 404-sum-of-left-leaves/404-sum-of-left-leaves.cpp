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

    void dfs(TreeNode* root, int &sum) {
        
        if(root == NULL)                        return;
        
        // To check whether this node is a left node
        if(root->left != NULL) {
            if(root->left->left == NULL && root->left->right == NULL) {
                sum += (root->left->val);
            }
        }
        
        dfs(root->left, sum);
        dfs(root->right, sum);
        
        return;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
    
        int sum = 0;
        
        if(root == NULL)                        return 0;
        
        dfs(root, sum);
        return sum;
    }
    
};