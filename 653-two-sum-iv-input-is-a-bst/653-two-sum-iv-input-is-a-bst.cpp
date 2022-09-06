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
   
    void inorder(TreeNode* root, vector<int> &v) {
        
        if(root == NULL)                        return;
        
        // inorder means left -> root -> right
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        
        return;
    }
    
    bool findTarget(TreeNode* root, int k) {
    
        if(root == NULL)                                    return false;
        if(root->left == NULL && root->right == NULL)       return false;
        
        vector<int> v;
        inorder(root, v);
        
        for(int i=0; i<v.size()-1; i++) {
            
            int t = v[i];
            auto it = find(v.begin() + i + 1, v.end(), k - t);
            
            if(it != v.end())                   return true;
        }
        
        return false;
    }
    
};