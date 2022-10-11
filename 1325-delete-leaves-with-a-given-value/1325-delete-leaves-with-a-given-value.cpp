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
    
    void deleteNodes(TreeNode* &root, int target, bool &flag) {
        
        if(root == NULL)                            return;
        
        if(root->left == NULL && root->right == NULL) {
            
            if(root->val == target) {
                
                flag = true;
                root = NULL;
                
                return;
            }
        }
        
        deleteNodes(root->left, target, flag);
        deleteNodes(root->right, target, flag);
        
        return;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
    
        if(root == NULL)                            return NULL;
        
        // Delete all leaf nodes having val target
        
        while(true) {
            
            bool flag = false;
            
            deleteNodes(root, target, flag);
            if(flag == false)                           break;
        }
        
        return root;
    }
    
};