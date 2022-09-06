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

    void sumAllNodes(TreeNode* root, int &t) {
        
        if(root == NULL)                        return;
        
        t += root->val;
        
        sumAllNodes(root->left, t);
        sumAllNodes(root->right, t);
        
        return;
    }
    
    void dfs(TreeNode* root, int &sum) {
        
        if(root == NULL)                        return;
        
        int temp = 0, t = 0;
        
        // For every node
        sumAllNodes(root->left, t);
        temp = t;
        
        t = 0;
        
        sumAllNodes(root->right, t);
        temp = abs(temp - t);
        
        sum += temp;
        
        dfs(root->left, sum);
        dfs(root->right, sum);
        
        return;
    }
    
    int findTilt(TreeNode* root) {
    
        int res = 0;
        
        if(root == NULL)                        return res;
        
        dfs(root, res);
        
        return res;
    }
    
};