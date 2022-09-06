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
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        
        return;
    }

    TreeNode* ans = NULL;
    
    void makeBT(TreeNode* &res, vector<int> v) {
        
        if(v.size() == 0)                      return;
        
        int n = v.size();
        res = new TreeNode(v[0]);
        
        ans = res;
        
        for(int i=1; i<n; i++) {
            
            TreeNode* temp = new TreeNode(v[i]);
            res->right = temp;
            
            res = temp;
        }
        
        return;
    }
    
    TreeNode* increasingBST(TreeNode* root) {

        TreeNode* res = NULL;
        
        if(root == NULL)                        return res;
        
        vector<int> v;
        inorder(root, v);
        
        // v contains all the nodes values in ascending order
        
        makeBT(res, v);
        return ans;
    }
    
};