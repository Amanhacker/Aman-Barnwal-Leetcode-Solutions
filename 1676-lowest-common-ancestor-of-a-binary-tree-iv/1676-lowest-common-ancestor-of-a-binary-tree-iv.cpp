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
  
    TreeNode* findLCA(TreeNode* root, unordered_set<TreeNode*> &w) {
        
        TreeNode* res = NULL;
        
        if(root == NULL)                                    return NULL;
        
        if(w.count(root))                                   return root;
        
        TreeNode* l = findLCA(root->left, w);
        TreeNode* r = findLCA(root->right, w);
        
        if(l != NULL && r != NULL)                          res = root;
        else if(l != NULL)                                  res = l;
        else if(r != NULL)                                  res = r;
       
        return res;
    }    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
    
        TreeNode* res = NULL;
        
        // Find the LCA of all the nodes which are present in vector "nodes"
        
        unordered_set<TreeNode*> w;
        for(auto &x : nodes)                                     w.insert(x);
        
        res = findLCA(root, w);
        return res;
    }
    
};