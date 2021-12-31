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
    
    void inorder(TreeNode* root, vector<int> &res) {
        
        if(root == NULL)                                        return;
        
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
        
        return;
    }
    
    // Recursively construct the balanced BST
    TreeNode* constructBST(vector<int> res, int start, int end) {
        
        if(start > end)                                        return NULL;
        
        int mid = start + (end - start) / 2;
        
        TreeNode* root = new TreeNode(res[mid]);
        
        root->left = constructBST(res, start, mid - 1);
        root->right = constructBST(res, mid + 1, end);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
    
        if(root == NULL)                                        return NULL;
        
        vector<int> res;
        inorder(root, res);
        
        int n = res.size();
        
        // Vector res contains element in sorted order
        // Construct a new balanced BST from res vector recursively
        
        return constructBST(res, 0, n-1);
    }
    
};