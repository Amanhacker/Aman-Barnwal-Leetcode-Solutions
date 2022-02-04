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
        
        int i = 0, j = res2.size() - 1;
        
        while(i < res1.size() && j >= 0) {
            
            if(res1[i] + res2[j] == target)                            return true;
            else if(res1[i] + res2[j] > target)                        j--;
            else if(res1[i] + res2[j] < target)                        i++;
        }
        
        return false;
    }
    
};