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
    
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
    
        if(root1 == NULL && root2 == NULL)                                      return true;
        if(root1 == NULL || root2 == NULL)                                      return false;
        
        queue<TreeNode*> q;
        
        q.push(root1);
        q.push(root2);
        
        while(q.empty() == false) {
            
            TreeNode* temp1 = q.front();
            q.pop();
            
            TreeNode* temp2 = q.front();
            q.pop();
            
            if(temp1 == NULL && temp2 == NULL)                                  continue;
            if(temp1 == NULL || temp2 == NULL)                                  return false;
            
            if(temp1->val != temp2->val)                                        return false;
            
            q.push(temp1->left);
            q.push(temp2->left);
            
            q.push(temp1->right);
            q.push(temp2->right);
        }
        
        return true;
    }
    
};