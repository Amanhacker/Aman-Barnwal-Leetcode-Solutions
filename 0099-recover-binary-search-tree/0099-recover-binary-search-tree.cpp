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
    
    
    void inorder(TreeNode* root, vector<TreeNode*> &res) {
        
        if(root == NULL)                    return;
        
        // inorder means left -> root -> right
        
        inorder(root->left, res);
        res.push_back(root);
        inorder(root->right, res);
        
        return;
    }
    
    void recoverTree(TreeNode* root) {
    
        if(root == NULL)                                return;
        
        vector<TreeNode*> res;
        inorder(root, res);

        // Ideally, inorder of BST gives us the nodes in strictly increasing order
        
        // But, in this swapped BST, the position of two BST are wrong
        // So, find those dip, and take the 1st node of 1st dip and 2nd node of 2nd dip
        
        int n = res.size();
        
        TreeNode* node1 = NULL, *node2 = NULL;
        
        for(int i=1; i<n; i++) {
            
            // If a dip is found
            if(res[i-1]->val > res[i]->val) {
                
                if(node1 == NULL)                      node1 = res[i-1];
                node2 = res[i];
            }
        }
        
        swap(node1->val, node2->val);
        return;
    }
    
};