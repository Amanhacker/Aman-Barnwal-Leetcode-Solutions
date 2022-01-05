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
    
    // Using Morris Traversal Algorithm
    
    void flatten(TreeNode* root) {
    
        if(root == NULL)                                                return;
        
        while(root != NULL) {
            
            if(root->left != NULL) {
                
                TreeNode* left = root->left;
                TreeNode* cur = root->left;
                
                // Go to extreme right node of cur
                while(cur->right != NULL) {
                    cur = cur->right;
                }
                
                // Here, cur is the extreme right node of left subtree
                // So, attach cur->right to right of root
                cur->right = root->right;
                
                // Make left of root to be NULL
                root->left = NULL;
                
                // Attach left subtree to right of root
                root->right = left;
            }
            
            root = root->right;
        }
        
        return;
    }
    
};