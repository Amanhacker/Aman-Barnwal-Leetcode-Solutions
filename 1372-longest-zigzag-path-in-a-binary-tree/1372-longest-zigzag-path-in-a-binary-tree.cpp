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
    
    class pairAns {
       
        public:
            
            int forwardSlope = -1;
            int backwardSlope = -1;
            int maxLen = 0;                 // Length of longest zigzag path
    };
    
    pairAns longestZigZagHelper(TreeNode* root) {
        
        pairAns ans;
       
        if(root == NULL)                                return ans;

        pairAns left = longestZigZagHelper(root->left);
        pairAns right = longestZigZagHelper(root->right);
        
        // To find maxLen. ans can be present at either side - including root, or excluding root
        
        // if I'll include root, I need to check max(left.backwardSlope, right.forwardSlope) + 1
        
        // If i'll exclude root, then either left subtree or right subtree can give the longest zigzag path
        // i.e maxLen = max(left.maxLen, right.maxLen)
        
        // Now, to find maxLen of the tree starting from cur node, we have to find the maximum of the above two 
        
        int maxLen_IncludingRoot = max(left.backwardSlope, right.forwardSlope) + 1;
        int maxLen_ExcludingRoot = max(left.maxLen, right.maxLen);
        
        ans.maxLen = max(maxLen_IncludingRoot, maxLen_ExcludingRoot);
        
        ans.forwardSlope =  left.backwardSlope + 1;
        ans.backwardSlope = right.forwardSlope + 1;
        
        return ans;
    }
    
    int longestZigZag(TreeNode* root) {
    
        if(root == NULL)                        return 0;
        
        pairAns ans = longestZigZagHelper(root);
        return ans.maxLen;
        
    }
    
};