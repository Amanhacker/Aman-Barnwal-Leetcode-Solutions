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
    
    void helperFindLeaves(TreeNode* &root, vector<int> &path) {
        
        if(root == NULL)                                       return;
        
        TreeNode* temp = root;
        
        // Base Condition
        if(root->left == NULL && root->right == NULL) {
            path.push_back(root->val);
            root = NULL;
        }
        
        helperFindLeaves(temp->left, path);
        helperFindLeaves(temp->right, path);
        
        return;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
    
        vector<vector<int>> res;
        
        if(root == NULL)                                        return res;
        
        while(root != NULL) {
            
            vector<int> path;
            helperFindLeaves(root, path);
            
            res.push_back(path);
            path.clear();
        }
        
        return res;
    }
    
};