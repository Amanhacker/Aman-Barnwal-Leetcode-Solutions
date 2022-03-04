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
    
    void bfs(TreeNode* root, bool &flag) {
        
        if(root == NULL || flag == false)                return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int lev = 0;
        
        while(q.empty() == false) {
            
            int n = q.size();
            vector<int> path;
            
            for(int i=0; i<n; i++) {
                
                TreeNode* temp = q.front();
                q.pop();

                path.push_back(temp->val);
                
                if(temp->left != NULL)                  q.push(temp->left);
                if(temp->right != NULL)                 q.push(temp->right);
            }

            if(lev % 2 == 0) {
                
                // It should be strictly increasing from left to right, and should be odd
                if(path[0] % 2 == 0) {
                    flag = false;
                    return;
                }
                
                for(int i=1; i<path.size(); i++) {
                
                    if(path[i] % 2 == 0 || path[i-1] >= path[i]) {
                        flag = false;
                        return;
                    }
                }
            }
            
            else {
                
                // It should be strictly decreasing from left to right, and should be even
                
                if(path[0] % 2 == 1) {
                    flag = false;
                    return;
                }
                
                for(int i=1; i<path.size(); i++) {
                    
                    if(path[i] % 2 == 1 || path[i-1] <= path[i]) {
                        flag = false;
                        return;
                    }
                }
            }
            
            lev++;
        }
        
        return;
    }
    
    bool isEvenOddTree(TreeNode* root) {
    
        if(root == NULL)                                return false;
        
        // For even- indexed level, nodes are odd in strictly increasing from left to right
        // For odd- indexed level,  nodes are odd in strictly decreasing from left to right
        
        // Considering 0-based level indexing
        
        if(root->val % 2 == 0)                          return false;
        
        bool flag = true;
        bfs(root, flag);
        
        return flag;
    }
    
};