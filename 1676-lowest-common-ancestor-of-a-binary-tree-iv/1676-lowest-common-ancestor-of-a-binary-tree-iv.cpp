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
  
    int traverse(TreeNode* root, unordered_set<TreeNode*> &w, TreeNode* &res, int n) {
        
        if(root == NULL)                                    return 0;
        
        int l = traverse(root->left, w, res, n);
        int r = traverse(root->right, w, res, n);
        
        if(w.count(root)) {
            if(res == NULL && l + r + 1 == n)               res = root;
            return l + r + 1;
        }
        
        if(res == NULL && l + r == n)                       res = root;
        
        return (l + r);
    }    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
    
        TreeNode* res = NULL;
        
        // Find the LCA of all the nodes which are present in vector "nodes"
        int n = nodes.size();
        
        unordered_set<TreeNode*> w;
        for(auto &x : nodes)                                     w.insert(x);
        
        traverse(root, w, res, n);
        return res;
    }
    
};