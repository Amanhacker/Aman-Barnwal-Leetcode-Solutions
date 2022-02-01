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
    
    void inorder(TreeNode* root, int low, int high, int &sum) {
  
      if(root == NULL)                                   return;

      // inorder means left -> root -> right

      if(root->val > low)                                inorder(root->left, low, high, sum);  

      if(root->val >= low && root->val <= high)          sum += root->val;

      if(root->val > high)                               return;

      inorder(root->right, low, high, sum);

      return;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
    
        if(root == NULL)                                            return 0;
        
        int sum = 0;
        inorder(root, low, high, sum);

        return sum;
    }
    
};