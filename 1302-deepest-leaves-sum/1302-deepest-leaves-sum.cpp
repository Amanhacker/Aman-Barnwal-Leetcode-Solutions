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

    void bfs(TreeNode* root, int &res) {
        
        if(root == NULL)                                    return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false) {
            
            int n = q.size();
            int sum = 0;
            
            for(int i=0; i<n; i++) {
                
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left == NULL && temp->right == NULL) {
                    sum += temp->val;
                }
                
                if(temp->left != NULL)                      q.push(temp->left);
                if(temp->right != NULL)                     q.push(temp->right);
            }
            
            res = sum;
        }
        
        return;
    }
    
    int deepestLeavesSum(TreeNode* root) {
    
        int res = 0;
        
        if(root == NULL)                                    return res;
        
        bfs(root, res);
        return res;
    }
    
};