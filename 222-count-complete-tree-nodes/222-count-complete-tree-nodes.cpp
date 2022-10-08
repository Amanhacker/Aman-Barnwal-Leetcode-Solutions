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
    
    void dfs(TreeNode* root, int &res) {
        
        if(root == NULL)                        return;
        
        res++;
        
        dfs(root->left, res);
        dfs(root->right, res);
        
        return;
    }
    
    int countNodes(TreeNode* root) {
    
        int res = 0;
        
        if(root == NULL)                        return res;
        
        dfs(root, res);
        return res;
    }
    
};