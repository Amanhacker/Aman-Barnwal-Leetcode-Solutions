/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* res = NULL;

        if(root == NULL)                                    return NULL;
        if(root->val == p->val || root->val == q->val)      return root;
        
        TreeNode* l = findLCA(root->left, p, q);
        TreeNode* r = findLCA(root->right, p, q);
        
        if(l != NULL && r != NULL)                          res = root;
        else if(l != NULL)                                  res = l;
        else if(r != NULL)                                  res = r;
        
        return res;
    }
    
    void inorder(TreeNode* root, vector<int> &v) {
        
        if(root == NULL)                                    return;
        
        // inorder means left -> root -> right
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        
        return;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
        TreeNode* res = NULL;
        
        // If either of p and q is not present in BT, then return res
        bool flag = false;
        
        vector<int> v;
        inorder(root, v);
        
        auto it1 = find(v.begin(), v.end(), p->val);
        auto it2 = find(v.begin(), v.end(), q->val);
        
        if(it1 == v.end() || it2 == v.end())                 return NULL;
        
        res = findLCA(root, p, q);
        return res;
    }
    
};