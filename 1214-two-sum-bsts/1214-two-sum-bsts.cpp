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
  
    void inorder(TreeNode* root, vector<int> &res) {
        
        if(root == NULL)                                                        return;
        
        // inorder means left -> root -> right
        
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
        
        return;
    }
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
    
        if(root1 == NULL && root2 == NULL)                                      return false;
        
        vector<int> res1, res2;
        
        // Inorder of BST gives us sorted array
        
        inorder(root1, res1);
        inorder(root2, res2);
        
        for(auto &x : res1) {
            // Check whether (target - x) present in res2
            if(find(res2.begin(), res2.end(), target - x) != res2.end())        return true;
        }
        
        return false;
    }
    
};