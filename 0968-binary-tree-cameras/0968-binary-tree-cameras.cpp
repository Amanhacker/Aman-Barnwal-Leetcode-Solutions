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

    void dfs(TreeNode* node, TreeNode* par, int &camCount, set<TreeNode*> &covered) {
        
        if(node == NULL)                        return;
        
        if(node != NULL) {
            
            dfs(node->left, node, camCount, covered);
            dfs(node->right, node, camCount, covered);
            
            // Here, you go to bottom level of the tree
            
            // Check if I need to add camera at node
            
            // if (par is NULL && node is uncovered) || any of left or right node is uncovered
            if( (par == NULL && covered.find(node) == covered.end()) || 
                covered.find(node->left) == covered.end() || 
                covered.find(node->right) == covered.end() ) {
                
                camCount++;
                
                // Cover node, par, and its left and right child
                covered.insert(node);
                covered.insert(par);
                covered.insert(node->left);
                covered.insert(node->right);
            }
        }
        
        return;
    }
    
    int minCameraCover(TreeNode* root) {
        
        int camCount = 0;
        set<TreeNode*> covered;
        
        if(root == NULL)                        return camCount;
    
        covered.insert(NULL);
        
        dfs(root, NULL, camCount, covered);
        return camCount;
    }
    
};
