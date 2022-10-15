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

    string solve(TreeNode* root, vector<TreeNode*> &res, unordered_map<string, int> &u) {
        
        if(root == NULL)                        return "#";
        
        // postorder = left -> right -> root
        string s = solve(root->left, res, u) + "," + solve(root->right, res, u) + "," + to_string(root->val);
        
        u[s]++;
        
        if(u[s] == 2)                           res.push_back(root);
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    
        vector<TreeNode*> res;
        
        if(root == NULL)                        return res;
        
        unordered_map<string, int> u;
        
        solve(root, res, u);
        return res;
    }
    
};