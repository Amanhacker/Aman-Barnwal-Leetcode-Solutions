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
        
        if(root == NULL)                                            return;
        
        inorder(root->right, res);
        res.push_back(root->val);
        inorder(root->left, res);
        
        return;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
    
        if(root == NULL)                                            return NULL;
        
        // right, root, left 
        // reverse inorder of BST gives us the sorted array in decreasing order
        
        vector<int> res;
        inorder(root, res);
        
        TreeNode* ans = NULL;
        
        int i = 0;
        
        for(auto &x : res) {
            
            TreeNode* temp = new TreeNode(x);
            
            if(i == 0)                                              ans = temp;
            else {
                temp->right = ans;
                ans = temp;
            }   
            
            i++;
        }
        
        return ans;
    }
    
};