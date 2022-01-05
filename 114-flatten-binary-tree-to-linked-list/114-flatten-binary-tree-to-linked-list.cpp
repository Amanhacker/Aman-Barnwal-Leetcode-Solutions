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
    
    void flatten(TreeNode* root) {
    
        if(root == NULL)                                                return;
        
        TreeNode* tempLeft = root->left;
        TreeNode* tempRight = root->right;
        
        // Make the left child of node to be NULL
        root->left = NULL;
      
        flatten(tempLeft);
        flatten(tempRight);
      
        // Append tempLeft to right of root node
        root->right = tempLeft;
        
        // Now, go to last node of tempLeft and append it to tempRight
        TreeNode* temp = root;
        
        while(temp->right != NULL) {
            temp = temp->right;
        }
        
        temp->right = tempRight;
        return;
    }
    
};