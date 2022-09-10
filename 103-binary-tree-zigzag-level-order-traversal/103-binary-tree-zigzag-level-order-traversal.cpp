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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
        vector<vector<int>> res;
        
        if(root == NULL)                        return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> path;
        
        // 1-based indexing
        
        // Even level - Right to left
        // Odd level - Left to right
        
        int i = 1;
        
        while(q.empty() == false) {
            
            int n = q.size();
            
            for(int i=0; i<n; i++) {

                TreeNode* temp = q.front();
                q.pop();
                
                path.push_back(temp->val);
                
                if(temp->left != NULL)          q.push(temp->left);
                if(temp->right != NULL)         q.push(temp->right);
            }
            
            if(i % 2 == 0)             reverse(path.begin(), path.end());
            
            res.push_back(path);
            path.clear();
            
            i++;
        }
        
        return res;
    }
    
};