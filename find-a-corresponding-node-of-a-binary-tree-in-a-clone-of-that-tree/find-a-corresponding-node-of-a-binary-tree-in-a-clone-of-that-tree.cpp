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
    
    bool sameTree(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == NULL && root2 == NULL)                                              return true;
        if(root1 == NULL || root2 == NULL)                                              return false;
        
        return (root1->val == root2->val) && sameTree(root1->left, root2->left) && sameTree(root1->right, root2->right);
    }
    
    void inorder(TreeNode* root, TreeNode* tar, TreeNode* &res) {
        
        if(root == NULL)                                                                return;
        if(res != NULL)                                                                 return;
        
        if( (root->val == tar->val) && sameTree(root, tar) == true) {
            res = root;
            return;
        }
        
        inorder(root->left, tar, res);
        inorder(root->right, tar, res);
        
        return;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    
        TreeNode* res = NULL;
        
        if(target == NULL || original == NULL)                                          return NULL;
        
        inorder(cloned, target, res);
        return res;
    }
    
};