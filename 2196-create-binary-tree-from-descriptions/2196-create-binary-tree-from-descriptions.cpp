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
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    
        TreeNode* root = NULL;
        
        unordered_map<int, TreeNode*> u;
        set<int> children;
        
        for(auto &x : descriptions) {
            
            int par = x[0];
            int child = x[1];
            int isLeft = x[2];
            
            if(u[par] == NULL)                      u[par] = new TreeNode(par);
            if(u[child] == NULL)                    u[child] = new TreeNode(child);
            
            // p -> ch
            
            // ch is left child of node p
            if(isLeft == 1)                         u[par]->left = u[child];
            else                                    u[par]->right = u[child];
            
            children.insert(child);
        }
        
        for(auto &x : descriptions) {
            if(children.find(x[0]) == children.end())         return u[x[0]];
        }
            
        return root;
    }
    
};