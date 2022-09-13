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
    
    void inorder(TreeNode* root, vector<int> &v) {
        
        if(root == NULL)                        return;
        
        // inorder means left -> root -> right
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        
        return;
    }
    
    bool isValidBST(TreeNode* root) {
    
        if(root == NULL)                        return true;
        
        vector<int> v; 
        inorder(root, v);
        
        for(int i=1; i<v.size(); i++) {
            if(v[i-1] >= v[i])                  return false;
        }
        
        return true;
    }
    
};