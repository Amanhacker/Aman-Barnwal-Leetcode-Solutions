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

    void findMinMax(TreeNode* root, TreeNode* node, int &mini, int &maxi) {
        
        if(node == NULL)                            return;
        
        // For any node in the subtree of root node
        if(node != root) {
            mini = min(mini, node->val);
            maxi = max(maxi, node->val);
        }
        
        findMinMax(root, node->left, mini, maxi);
        findMinMax(root, node->right, mini, maxi);
        
        return;
    }
    
    bool isLeafNode(TreeNode* root) {
        return (root->left == NULL && root->right == NULL);
    }
    
    // For each node, find the min and max value of its descendants of its subtree
    
    void dfs(TreeNode* root, int &res) {
        
        if(root == NULL)                            return;
        
        int mini = INT_MAX, maxi = INT_MIN;
        
        if(isLeafNode(root) == false) {
           
            findMinMax(root, root, mini, maxi);
            
            int diff = max( abs(root->val - maxi), abs(root->val - mini) );
            res = max(res, diff);
        }
        
        dfs(root->left, res);
        dfs(root->right, res);
        
        return;
    }
    
    int maxAncestorDiff(TreeNode* root) {
    
        int res = INT_MIN;
        
        if(root == NULL)                            return res;
        
        dfs(root, res);
        
        return res;
    }
    
};