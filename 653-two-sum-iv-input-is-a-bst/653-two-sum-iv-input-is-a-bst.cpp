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
        
        if(root == NULL)                                        return;
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        
        return;
    }
    
    bool findTarget(TreeNode* root, int k) {
    
        if(root == NULL)                                        return false;
    
        vector<int> v;
        inorder(root, v);

        int low = 0, high = v.size() - 1;
        
        while(low < high) {
            
            if(v[low] + v[high] == k)                           return true;
            else if(v[low] + v[high] > k)                       high--;
            else if(v[low] + v[high] < k)                       low++;
        }
        
        return false;
    }
    
};