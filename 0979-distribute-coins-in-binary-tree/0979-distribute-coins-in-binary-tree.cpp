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

    int dfs(TreeNode* node, int &count) {
        
        if(node == NULL)                        return 0;
        
        int l = dfs(node->left, count);
        int r = dfs(node->right, count);
        
        count += abs(l) + abs(r);
        
        return node->val + (l + r - 1);
    }
    
    int distributeCoins(TreeNode* root) {
    
        int count = 0;
        
        if(root == NULL)                        return count;
        
        dfs(root, count);
        return count;
    }
    
};