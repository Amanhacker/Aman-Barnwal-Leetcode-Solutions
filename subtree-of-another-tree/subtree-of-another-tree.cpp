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
    
    bool sameTree(TreeNode* t1, TreeNode* t2) {
        
        if(t1 == NULL && t2 == NULL)                    return true;
        if(t1 == NULL || t2 == NULL)                    return false;
        
        return (t1->val == t2->val) && sameTree(t1->left, t2->left) && sameTree(t1->right, t2->right);
    }
    
    void preorder(TreeNode* root, TreeNode* &subRoot, bool &flag) {
        
        if(root == NULL)                                return;
        if(flag == true)                                return;
        
        if(root->val == subRoot->val && sameTree(root, subRoot) == true) {
            flag = true;
            return ;
        }
        
        preorder(root->left, subRoot, flag);
        preorder(root->right, subRoot, flag);
        
        return;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    
        if(root == NULL && subRoot == NULL)                                            return true;
        if(root == NULL || subRoot == NULL)                                            return false;
        
        bool flag = false;
        preorder(root, subRoot, flag);
        
        return flag;
    }
    
};