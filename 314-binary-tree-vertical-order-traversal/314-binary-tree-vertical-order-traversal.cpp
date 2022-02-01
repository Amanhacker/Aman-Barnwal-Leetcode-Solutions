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
    
    unordered_map<int, vector<int>> mp;
    unordered_map<TreeNode*, int> u;
    
    int height(TreeNode* root) {
        
        if(root == NULL)                                               return 0;
        
        int l = height(root->left);
        int r = height(root->right);
        
        return 1 + max(l, r);
    }
    
    // Level Order Traversal
    void levelOrder(TreeNode* root, int depth, int lev) {
        
        if(root == NULL)                                               return;
        
        u[root] = depth;
            
        if(lev == 1)                                                    mp[depth].push_back(root->val);
            
        else if(lev > 1) {
        
            if(root->left != NULL)                                      levelOrder(root->left, u[root] - 1, lev - 1);
            if(root->right != NULL)                                     levelOrder(root->right, u[root] + 1, lev - 1);
        }
        
        return;
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
    
        vector<vector<int>> res;
        
        if(root == NULL)                                                return res;
        
        // Find Vertical Order Traversal of the given BT
        unordered_map<TreeNode*, int> u;
        vector<pair<int, vector<int>>> v;
        
        int h = height(root);
        int dep = 0;
        
        for(int i=1; i<=h; i++) {
            levelOrder(root, u[root], i);
        }   
                
        for(auto &x : mp)                                               v.push_back({x.first, x.second});
        sort(v.begin(), v.end());
        
        for(auto &x : v)                                                res.push_back(x.second);    
        
        return res;
    }
    
};