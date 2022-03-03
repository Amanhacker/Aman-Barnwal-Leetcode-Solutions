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

    TreeNode* buildTreeHelper(vector<int> preorder, vector<int> inorder, int preStart, int preEnd, int inStart, int inEnd) {
        
        // Base Condition
        if(preStart > preEnd || inStart > inEnd)                        return NULL;
        
        int preLeftStart, preLeftEnd, inLeftStart, inLeftEnd;
        int preRightStart, preRightEnd, inRightStart, inRightEnd;
        
        // preorder means root -> left -> right
        // inorder means left -> root -> right
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        // Find index of root in inorder
        int rootIndex;
        
        for(int i=inStart; i<=inEnd; i++) {
            if(inorder[i] == root->val) {
                rootIndex = i;
                break;
            }
        }
        
        inLeftStart = inStart;
        inRightEnd = inEnd;
        
        inLeftEnd = rootIndex - 1;
        inRightStart = rootIndex + 1;
        
        preLeftStart = preStart + 1;
        preRightEnd = preEnd;

        // preLeftEnd - preLeftStart = inLeftEnd - inLeftStart
        preLeftEnd = preLeftStart + inLeftEnd - inLeftStart;
        preRightStart = preLeftEnd + 1;
      
        root->left = buildTreeHelper(preorder, inorder, preLeftStart, preLeftEnd, inLeftStart, inLeftEnd);
        root->right = buildTreeHelper(preorder, inorder, preRightStart, preRightEnd, inRightStart, inRightEnd);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
        TreeNode* root = NULL;
        
        int n = preorder.size();
        
        if(n == 0)                                          return root;
        
        // preorder means root -> left -> right
        // inorder means left -> root -> right
        
        root = buildTreeHelper(preorder, inorder, 0, n-1, 0, n-1);
        return root;
    }
    
};