/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
        if(root == NULL)                        return root;
        
        // if cur node value is less than p and q then LCA lies in right subtree
        if(root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        // if cur node value is greater than p and q then LCA lies in left subtree
        if(root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);   
        }
        
        return root;
    }
    
};