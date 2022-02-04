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
   
    set<TreeNode*> w;
    
    TreeNode* correctBinaryTree(TreeNode* root) {
    
        if(root == NULL)                                                    return NULL;
        
        if(root->right != NULL && w.find(root->right) != w.end())           return NULL;
        
        root->right = correctBinaryTree(root->right);
        root->left = correctBinaryTree(root->left);
            
        w.insert(root);
        return root;
    }
    
};