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
    
    void preorder(TreeNode* root, vector<int> &res) {
        
        if(root == NULL)                        return;
        
        // preorder means root -> left -> right
        
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
        
        return;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
    
        vector<int> res;
        
        if(root == NULL)                        return res;
        
        preorder(root, res);
        
        return res;
    }
    
};