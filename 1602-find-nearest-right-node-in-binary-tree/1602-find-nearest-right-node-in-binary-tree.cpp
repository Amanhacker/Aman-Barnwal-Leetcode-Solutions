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
    
    void bfs(TreeNode* root, TreeNode* u, TreeNode* &res) {
        
        if(root == NULL)                                  return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false) {
            
            int n = q.size();
            
            // At one level, it has n nodes
            int i = 0, j = -1;
            bool flag = false;
            
            for( ; i<n; i++) {
                
                TreeNode* temp = q.front();
                q.pop();
                
                // If u is the rightmost node at a level
                if(i == n-1 && temp == u) {
                    res = NULL;
                    return;
                }

                // if u is not the rightmost node at a level
                if(flag == true && i == j) {
                    res = temp;
                    return;
                }
                
                if(i < n-1 && temp == u) {
                    j = i + 1;
                    flag = true;
                }
                
                if(temp->left != NULL)                      q.push(temp->left);
                if(temp->right != NULL)                     q.push(temp->right);
            }
        }
        
        return;
    }
    
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
    
        TreeNode* res = NULL;
        
        if(root == NULL)                                    return res;
        
        bfs(root, u, res);
        return res;
    }
    
};