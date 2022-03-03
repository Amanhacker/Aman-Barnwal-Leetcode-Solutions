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

    int height(TreeNode* root) {
        
        if(root == NULL)                                    return 0;
        
        int l = height(root->left);
        int r = height(root->right);
        
        return 1 + max(l, r);
    }
    
    void findLevelOrder(TreeNode* root, int lev, vector<int> &path) {
        
        if(root == NULL)                                    return;
        
        if(lev == 1)                                        path.push_back(root->val);
        else if(lev > 1) {
            
            findLevelOrder(root->left, lev - 1, path);
            findLevelOrder(root->right, lev - 1, path);
        }
        
        return;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
    
        vector<vector<int>> res;
        
        if(root == NULL)                                    return res;
        
        int h = height(root);
        vector<int> path;
        
        for(int i=1; i<=h; i++) {
            
            findLevelOrder(root, i, path);
            
            res.push_back(path);
            path.clear();
        }
        
        return res;
    }
    
};