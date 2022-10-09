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
    
    void preorder(TreeNode* root, vector<int> &res) {
        
        if(root == NULL)                    return;
        
        // preorder means left -> root -> right
        
        preorder(root->left, res);
        res.push_back(root->val);
        preorder(root->right, res);
        
        return;
    } 
    
    void dfs(TreeNode* &root, unordered_map<int, int> &mp) {
        
        if(root == NULL)                    return;
        
        root->val = mp[root->val];
        
        dfs(root->left, mp);
        dfs(root->right, mp);
        
        return;
    }
    
    TreeNode* convertBST(TreeNode* root) {
    
        unordered_map<int, int> mp;
        
        vector<int> res;
        preorder(root, res);
        
        int n = res.size();
        int sum = 0;
        
        for(int i=n-1; i>=0; i--) {
            sum += res[i];
            mp[res[i]] = sum;
        }
        
        dfs(root, mp);
        return root;
    }
    
};