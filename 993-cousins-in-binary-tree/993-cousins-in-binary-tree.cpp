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
    
    void dfs(TreeNode* root, int x, int y, map<int, TreeNode*> &par, map<int, int> &dep, int d) {
        
        if(root == NULL)                            return;
        
        dep[root->val] = d;
        
        if(root->left != NULL) {
            par[root->left->val] = root;
            dfs(root->left, x, y, par, dep, d + 1);
        }
        
        if(root->right != NULL) {
            par[root->right->val] = root;
            dfs(root->right, x, y, par, dep, d + 1);
        }
        
        return;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
    
        if(root == NULL)                            return false;
        
        // Two nodes a and b are cousins if par[a] != par[b] && dep[a] == dep[b]
        
        map<int, TreeNode*> par;
        map<int, int> dep;
        
        dfs(root, x, y, par, dep, 0);
        
        return (par[x] != par[y]) && (dep[x] == dep[y]);
    }
    
};