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
    
    TreeNode* deleteNode(TreeNode* root, int key) {
    
        if(root == NULL)                        return NULL;
        
        else {
            
            // First find the node having value "key" and then delete the node
            
            if(key < root->val)                 root->left  = deleteNode(root->left, key);
            else if(key > root->val)            root->right = deleteNode(root->right, key);
            
            else {
                
                // Now, key is found
                
                if(root->left == NULL && root->right == NULL)           return NULL;
                
                else if(root->left == NULL || root->right == NULL) {
                    return root->left ? root->left : root->right;
                }
                
                else {
                    
                    // Root node having value "key" has both children
                    
                    TreeNode* temp = root->left;
                    
                    // Replace root value with greatest element in left subtree
                    while(temp->right != NULL)                      temp = temp->right;
                    
                    root->val = temp->val;
                    
                    // Now, delete greatest element node in left subtree since key is already replaced
                    root->left = deleteNode(root->left, temp->val);
                }
            }
        }
        
        return root;
    }
    
};