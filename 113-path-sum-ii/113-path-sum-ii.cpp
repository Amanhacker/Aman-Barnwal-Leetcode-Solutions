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
    
    void findAllPaths(TreeNode* root, int target, vector<int> path, vector<vector<int>> &res) {
        
        if(root == NULL)                                return;
        
        path.push_back(root->val);

        if(root->left == NULL && root->right == NULL) {
            
            int sum = 0;
            for(auto &x : path)                         sum += x;
            
            if(sum == target) {
                res.push_back(path);
            }           
        }
        
        findAllPaths(root->left, target, path, res);
        findAllPaths(root->right, target, path, res);
        
        path.pop_back();
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    
        vector<vector<int>> res;
        vector<int> path;

        if(root == NULL)                        return res;
        
        findAllPaths(root, targetSum, path, res);
        return res;
    }
    
};