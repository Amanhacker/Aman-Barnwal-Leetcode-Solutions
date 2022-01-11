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
        
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
        
        return;
    }
    
    bool findTarget(TreeNode* root, int k) {
    
        if(root == NULL)                                            return false;
        
        vector<int> a;
        inorder(root, a);
        
        int i = 0, j = a.size() - 1;
        
        // Now, res is the sorted array
        
        while(i < j) {
            
            if(a[i] + a[j] == k)                                   return true;
            else if(a[i] + a[j] > k)                               j--;
            else                                                   i++;
        }
        
        return false;
    }
    
};