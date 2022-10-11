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
    
    void bfs(TreeNode* &root) {
        
        if(root == NULL)                            return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int lev = 0;
        vector<int> values;
        
        while(q.empty() == false) {
            
            int n = q.size();
            vector<int> path;
            
            for(int i=0; i<n; i++) {
                
                TreeNode* temp = q.front();
                q.pop();
                
                if(lev % 2 == 1) {
                    temp->val = values[n - i - 1];
                }
                
                if(temp->left != NULL) {
                    q.push(temp->left);  
                    path.push_back(temp->left->val);
                }   
                
                if(temp->right != NULL) {
                    q.push(temp->right);                    
                    path.push_back(temp->right->val);
                } 
                
            }
            
            values = path;
            lev++;
        }
        
        return;
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
    
        if(root == NULL)                        return NULL;
        
        bfs(root);
        return root;
    }
    
};