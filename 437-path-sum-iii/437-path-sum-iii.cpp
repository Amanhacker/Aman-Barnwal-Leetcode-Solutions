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
    
    void dfs(TreeNode* root, vector<int> path, int target, int &res) {
        
        if(root == NULL)                            return;
        path.push_back(root->val);
        
        int n = path.size();
        int sum = 0;

        for(int i=n-1; i>=0; i--) {
            sum += path[i];
            if(sum == target)                   res++;
        }
        
        dfs(root->left, path, target, res);
        dfs(root->right, path, target, res);
        
        path.pop_back();
        return;
    }
    
    int pathSum(TreeNode* root, int targetSum) {

        int res = 0;
        
        if(root == NULL)                            return res;
        
        vector<int> path;
        dfs(root, path, targetSum, res);
        
        return res;
    }
    
};