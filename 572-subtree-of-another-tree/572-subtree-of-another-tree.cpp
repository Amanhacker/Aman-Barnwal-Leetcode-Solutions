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
   
    bool isIdentical(TreeNode* node1, TreeNode* node2) {
        
        if(node1 == NULL && node2 == NULL)              return true;
        if(node1 == NULL || node2 == NULL)              return false;
        
        return (node1->val == node2->val) && isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right);
        
    }
    
    void dfs(TreeNode* root, TreeNode* subRoot, bool &flag) {
        
        if(root == NULL)                        return;
        if(flag == true)                        return;
        
         if(root->val == subRoot->val) {
            // Then check whether this root, and subRoot are identical nodes
            flag = isIdentical(root, subRoot);
        }
        
        dfs(root->left, subRoot, flag);
        dfs(root->right, subRoot, flag);
        
        return;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    
        if(subRoot == NULL)                     return false;
        if(root == NULL)                        return (subRoot == NULL);
        
        bool flag = false;
        dfs(root, subRoot, flag);
        
        return flag;
    }
    
};