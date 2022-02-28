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

    int maxi = INT_MIN;
    
    void dfs(TreeNode* root, vector<int> path) {
        
        if(root == NULL)                            return;
        
        path.push_back(root->val);
        
        // Base Condition
        if(root->left == NULL && root->right == NULL) {
            
            maxi = max(maxi, (int)(path.size()));
            path.clear();
        }
        
        dfs(root->left, path);
        dfs(root->right, path);
        
        return;
    }
    
    int maxDepth(TreeNode* root) {
    
        if(root == NULL)                    return 0;
        
        vector<int> path;
        dfs(root, path);
        
        return maxi;
    }
    
};