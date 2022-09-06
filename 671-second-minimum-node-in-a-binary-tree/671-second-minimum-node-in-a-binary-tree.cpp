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
    
    void dfs(TreeNode* root, set<int> &w) {
        
        if(root == NULL)                    return;
        
        w.insert(root->val);
        
        dfs(root->left, w);
        dfs(root->right, w);
        
        return;
    }
     
    int findSecondMinimumValue(TreeNode* root) {
    
        if(root == NULL)                    return -1;
        
        set<int> w;
        dfs(root, w);
        
        if(w.size() == 1)                   return -1;
        
        auto it = w.begin();
        it++;
        
        return *it;
    }
    
};