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
    
    int height(TreeNode* root) {
        
        if(root == NULL)                        return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return 1 + max(left, right);
    }
    
    // Level starts from 1 from root node
    void findLevel(TreeNode* root, int lev, int h, bool &isLeafFound) {
        
        if(root == NULL)                        return;
        
        if(root->left == NULL && root->right == NULL) {
            isLeafFound = true;
            return;
        }
        
        if(lev == 1)                            return;
        else if(lev > 1) {
           
            findLevel(root->left, lev-1, h, isLeafFound);
            findLevel(root->right, lev-1, h, isLeafFound);
        }
        
        return;
    }
    
    int minDepth(TreeNode* root) {
    
        if(root == NULL)                        return 0;
        
        // Go level by level, and stop when you first get the first leaf node
        
        // Level order traversal
        int ans = 0;
        
        int h = height(root);
        bool isLeafFound = false;
        
        for(int i=1; i<=h; i++) {
            findLevel(root, i, h, isLeafFound);
            if(isLeafFound == true)             return i;
        }
        
        return h;
    }
    
};