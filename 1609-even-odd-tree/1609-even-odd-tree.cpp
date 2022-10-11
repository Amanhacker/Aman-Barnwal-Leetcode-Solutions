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
    
    bool bfs(TreeNode* root) {
        
        if(root == NULL)                            return true;

        bool flag = true;
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> path;
        int lev = 0;
        
        while(q.empty() == false) {
            
            int n = q.size();
            
            while(n--) {
                
                TreeNode* temp = q.front();
                q.pop();
                
                path.push_back(temp->val);
                
                if(temp->left != NULL)              q.push(temp->left);
                if(temp->right != NULL)             q.push(temp->right);
            }
            
            // For odd-indexed level -> All even values -> All nodes strictly decreasing 
            if(lev % 2 == 1) {
                
                if(path[0] % 2 == 1)                    return false;
                
                for(int i=1; i<path.size(); i++) {
                    
                    if(path[i] % 2 == 1)                return false;
                    if(path[i-1] <= path[i])            return false;
                }
            }
            
            // For even-indexed level -> All odd values -> All nodes strictly increasing 
            else {
                
                if(path[0] % 2 == 0)                    return false;
                
                for(int i=1; i<path.size(); i++) {
                    
                    if(path[i] % 2 == 0)                return false;
                    if(path[i-1] >= path[i])            return false;
                }
            }
            
            lev++;
            path.clear();
        }
        
        return true;
    }
    
    bool isEvenOddTree(TreeNode* root) {
    
        if(root == NULL)                                return true;
        
        return bfs(root);
    }
    
};