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

    TreeNode* constructHelper(vector<int> &pre, vector<int> &post, int &preIndex, int &postIndex) {
        
        TreeNode* root = new TreeNode(pre[preIndex]);
        preIndex++;
        
        // Because root node will be lastly iterated in post order,
        // if (root.val == post[posIndex]), it means we have constructed the whole tree,
        
        if(root->val != post[postIndex])        root->left =  constructHelper(pre, post, preIndex, postIndex);
        if(root->val != post[postIndex])        root->right = constructHelper(pre, post, preIndex, postIndex);
           
        
        postIndex++;
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    
        TreeNode* root = NULL;
        
        // preorder means root -> left -> right
        // postorder means left -> right -> root
        
        int preIndex = 0, postIndex = 0;
        
        root = constructHelper(preorder, postorder, preIndex, postIndex);
        return root;
    }
    
};