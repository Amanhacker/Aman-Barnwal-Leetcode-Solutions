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
    
     void bfs(TreeNode* root, vector<TreeNode*> &deepest) {
        
        if(root == NULL)                            return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false) {
            
            int n = q.size();
            deepest.clear();
            
            while(n--) {
                
                TreeNode* temp = q.front();
                q.pop();
                
                deepest.push_back(temp);
                
                if(temp->left != NULL)              q.push(temp->left);
                if(temp->right != NULL)             q.push(temp->right);
            }
        }
        
        return;
    }
    
    TreeNode* findLCA(TreeNode* root, TreeNode* l, TreeNode* r) {
        
        if(root == NULL)                                        return NULL;
        
        if(root->val == l->val || root->val == r->val)          return root;
        
        TreeNode* left = findLCA(root->left, l, r);
        TreeNode* right = findLCA(root->right, l, r);
        
        if(left != NULL && right != NULL)                       return root;
        
        if(left != NULL)                                        return left;
        else                                                    return right;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        if(root == NULL)                            return NULL;
        
        // Find all deepest node and find the lca of all
        
        vector<TreeNode*> deepest;
        bfs(root, deepest);
        
        int n = deepest.size();
        
        if(n == 1)                                  return deepest[0];
        
        TreeNode* LCA = findLCA(root, deepest[0], deepest[1]);
        
        for(int i=2; i<n; i++) {
            LCA = findLCA(root, LCA, deepest[i]);
        }
        
        return LCA;
    }
    
};