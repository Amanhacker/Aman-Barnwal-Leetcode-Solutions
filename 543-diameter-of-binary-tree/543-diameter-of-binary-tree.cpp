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
    
    // Height of a node root
    int dfs(TreeNode* root, int &maxi) {
        
        if(root == NULL)               return 0;
        
        int l_height = dfs(root->left, maxi);
        int r_height = dfs(root->right, maxi);
        
        maxi = max(maxi, l_height + r_height);
        
        return 1 + max(l_height, r_height);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {

        int maxi = INT_MIN;
        
        if(root == NULL)                return 0;
        
        dfs(root, maxi);
        return maxi;
    }
    
};