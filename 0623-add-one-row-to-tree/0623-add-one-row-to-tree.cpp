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
    
    void insert(TreeNode* &node, int val, int d, int curDepth) {
        
        if(node == NULL)                        return;
        
        if(curDepth == d - 1) {
            
            // Here, we need to insert the node having value val
            
            // For left node
            TreeNode* temp = node->left;
            node->left = new TreeNode(val);
            node->left->left = temp;
            
            // For right node
            temp = node->right;
            node->right = new TreeNode(val);
            node->right->right = temp;
        }
        
        else {
            
            insert(node->left, val, d, curDepth + 1);
            insert(node->right, val, d, curDepth + 1);
        }
        
        return;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
    
        if(d == 1) {
            
            TreeNode* node = new TreeNode(val);
            node->left = root;
            
            return node;
        }
        
        insert(root, val, d, 1);
        return root;
    }
    
};