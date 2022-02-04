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
    
    // Return sum for current node root
    long dfs(TreeNode* root, int &res) {
        
        if(root == NULL)                                  return 0;
        
        long lSum = dfs(root->left, res);
        long rSum = dfs(root->right, res);

        if(lSum + rSum == root->val)                      res++;        
        
        return lSum + rSum + (root->val);
    }
    
    int equalToDescendants(TreeNode* root) {
    
        int res = 0;
        
        if(root == NULL)                                    return res;
        
        dfs(root, res);      
        
        return res;
    }
    
};