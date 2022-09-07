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
        
        if(root == NULL)                            return;
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        
        return;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
    
        int res = 0;
        
        vector<int> v;
        inorder(root, v);
        
        for(auto &x : v) {
            if(low <= x && x <= high)               res += x;
        }
        
        return res;
    }
    
};