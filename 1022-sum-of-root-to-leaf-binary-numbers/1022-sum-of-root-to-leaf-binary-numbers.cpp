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
    
    int findNumber(vector<int> v) {
        
        int sum = 0;
        int mul = 1;
        
        int n = v.size();
        
        for(int i=n-1; i>=0; i--) {
            sum += mul * v[i];
            mul *= 2;
        }
        
        return sum;
    }
    
    void dfs(TreeNode* root, vector<int> path, int &res) {
        
        if(root == NULL)                            return;
        
        path.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL) {
            
            int t = findNumber(path);
            res += t;
        }
        
        dfs(root->left, path, res);
        dfs(root->right, path, res);
        
        path.pop_back();
        
        return;
    }
    
    int sumRootToLeaf(TreeNode* root) {
    
        int res = 0;
        
        if(root == NULL)                            return res;
        
        vector<int> path;
        
        // Find all root to leaf paths
        
        dfs(root, path, res);
        
            
        return res;
    }
    
};