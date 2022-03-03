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
    
    void dfs(TreeNode* root, vector<int> &v) {
        
        if(root == NULL)                                return;
        
        v.push_back(root->val);
        
        dfs(root->left, v);
        dfs(root->right, v);
        
        return;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
    
        int sum = 0;
        if(root == NULL)                                return 0;
        
        vector<int> v;
        dfs(root, v);
        
        sort(v.begin(), v.end());
        
        for(auto &x : v) {
            if(low <= x && x <= high)                   sum += x;
        }
        
        return sum;
    }
    
};