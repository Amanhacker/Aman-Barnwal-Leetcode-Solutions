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
    
    void dfs(TreeNode* root, vector<int> &res) {
        
        if(root == NULL)                                          return;
        
        // If the current node has only left child
        if(root->left != NULL && root->right == NULL)             res.push_back(root->left->val);
        
        // If the current node has only right child
        if(root->left == NULL && root->right != NULL)             res.push_back(root->right->val);
        
        dfs(root->left, res);
        dfs(root->right, res);
        
        return;
    }
    
    vector<int> getLonelyNodes(TreeNode* root) {
    
        vector<int> res;
        
        if(root == NULL)                                    return res;
        
        dfs(root, res);
        
        return res;
    }
    
};