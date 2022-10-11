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
   
    void dfs(TreeNode* root, vector<TreeNode*> path,  set<TreeNode*> &w) {
        
        if(root == NULL)                        return;
        
        path.push_back(root);
        
        // To avoid redundact path 
        
        if(root->left == NULL && root->right == NULL) {
            
            int maxi = path[0]->val;

            for(int i=1; i<path.size(); i++) {
            
                // In path from root node to node i, find the max value
                // maxi is the max value from path[0] to path[i-1]

                if(maxi > path[i]->val)                     continue;
                else                                        w.insert(path[i]);

                maxi = max(maxi, path[i]->val);
            }
        }
        
        dfs(root->left, path, w);
        dfs(root->right, path, w);
        
        path.pop_back();
        return;
    }
    
    int goodNodes(TreeNode* root) {
    
        if(root == NULL)                        return 0;
        
        vector<TreeNode*> path;
        set<TreeNode*> w;
        
        dfs(root, path, w);
        int res = w.size() + 1;
        
        return res;
    }
    
};