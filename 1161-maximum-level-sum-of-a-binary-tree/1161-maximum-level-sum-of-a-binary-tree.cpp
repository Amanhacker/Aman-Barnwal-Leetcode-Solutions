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
    
    void bfs(TreeNode* root, map<int, int> &mp) {
        
        if(root == NULL)                                return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int lev = 1;
        
        while(q.empty() == false) {
            
            int n = q.size();
            int sum = 0;
            
            for(int i=0; i<n; i++) {
                
                TreeNode* temp = q.front();
                q.pop();
                
                sum += temp->val;
                
                if(temp->left != NULL)                  q.push(temp->left);
                if(temp->right != NULL)                 q.push(temp->right);
            }
            
            mp[lev] = sum;
            lev++;
        }
        
        return;
    }
    
    int maxLevelSum(TreeNode* root) {
    
        int minLev = INT_MAX;
        
        if(root == NULL)                                return -1;
        
        map<int, int> mp;
        bfs(root, mp);
        
        int sum = INT_MIN;
        
        for(auto &x : mp) {
           
            if(sum < x.second) {
                sum = x.second;
                minLev = x.first;
            }
        }
        
        return minLev;
    }
    
};