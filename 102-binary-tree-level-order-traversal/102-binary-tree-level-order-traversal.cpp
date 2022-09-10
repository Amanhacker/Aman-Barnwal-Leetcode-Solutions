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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
    
        vector<vector<int>> res;
        
        if(root == NULL)                    return res;
        
        vector<int> path;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(q.empty() == false) {
            
            int n = q.size();
            
            // All nodes at one level
            for(int i=0; i<n; i++) {
                
                TreeNode* temp = q.front();
                q.pop();
                
                path.push_back(temp->val);
                
                if(temp->left != NULL)           q.push(temp->left);
                if(temp->right != NULL)          q.push(temp->right);
            }
            
            res.push_back(path);
            path.clear();
        }
        
        
        return res;
    }
    
};