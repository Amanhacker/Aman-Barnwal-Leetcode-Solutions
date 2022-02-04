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
    
    // Distance between node "node" and node having value n
    int findDist(TreeNode* node, int n, int dist) {
        
        if(node == NULL)                                    return -1;
        if(node->val == n)                                  return dist;
        
        int d = findDist(node->left, n, dist + 1);
        if(d != -1)                                         return d;
        
        d = findDist(node->right, n, dist + 1);
        return d;
    }
    
    // Find LCA of two nodes having value p and q
    TreeNode* findLCA(TreeNode* root, int p, int q) {
    
        if(root == NULL)                                            return NULL;
        
        if(root->val == p || root->val == q)                        return root;
        
        TreeNode* l = findLCA(root->left, p, q);
        TreeNode* r = findLCA(root->right, p, q);
        
        if(l != NULL && r != NULL)                                  return root;
        
        if(l != NULL)                                               return l;
        else                                                        return r;
    }
    
    // Find distance between node having value p and q
    int findDistance(TreeNode* root, int p, int q) {
    
        if(root == NULL)                                    return 0;
        
        TreeNode* lca = findLCA(root, p, q);
        
        int ans;
        ans = findDist(lca, p, 0) + findDist(lca, q, 0);
        
        return ans;
    }
    
};