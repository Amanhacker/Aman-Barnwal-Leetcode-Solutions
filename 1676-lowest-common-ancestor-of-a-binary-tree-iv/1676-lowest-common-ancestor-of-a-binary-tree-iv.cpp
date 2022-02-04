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
  
    int traverse(TreeNode* root, unordered_set<TreeNode*> &w, TreeNode* &res) {
        
        int match;
        
        if(root == NULL)       match = 0;
        else                   match = w.count(root) + traverse(root->left, w, res) + traverse(root->right, w, res);
        
        if(match == w.size() && res == NULL)                    res = root;
        
        return match;
    }    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
    
        TreeNode* res = NULL;
        
        // Find the LCA of all the nodes which are present in vector "nodes"
        
        unordered_set<TreeNode*> w;
        for(auto &x : nodes)                                     w.insert(x);
        
        traverse(root, w, res);
        return res;
    }
    
};