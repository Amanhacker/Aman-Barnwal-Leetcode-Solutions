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
        
        if(root == NULL)                        return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false) {
            
            int n = q.size();
            int i = 0;
            
            while(n--) {
                
                TreeNode* temp = q.front();
                q.pop();
                
                if(i == 0)                       res = temp->val;
                i++;
                
                if(temp->left != NULL)           q.push(temp->left);
                if(temp->right != NULL)          q.push(temp->right);
            }
        }
        
        
        
        return;
    }
    
    int findBottomLeftValue(TreeNode* root) {
    
        int res;
        
        if(root == NULL)                        return 0;
        
        bfs(root, res);
        
        return res;
    }
    
};