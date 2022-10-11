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
    
    void dfs(TreeNode* root, TreeNode* par, TreeNode* grandpar, int &sum) {
        
        if(root == NULL)                        return;
        
        if(grandpar != NULL && int(grandpar->val) % 2 == 0) {
           sum += (root->val);            
        }   
        
        dfs(root->left, root, par, sum);
        dfs(root->right, root, par, sum);
        
        return;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
    
        int sum = 0;
        
        if(root == NULL)                        return 0;
        
        dfs(root, NULL, NULL, sum);
        
        
        return sum;
    }
    
};