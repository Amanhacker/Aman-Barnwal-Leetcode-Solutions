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
    
    TreeNode* convertBST(vector<int> v, int start, int end) {
        
        TreeNode* root = NULL;
        
        if(start > end)                                                    return NULL;
        
        int mid = start + (end - start) / 2;
        
        root = new TreeNode(v[mid]);
        
        root->left = convertBST(v, start, mid - 1);
        root->right = convertBST(v, mid + 1, end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& v) {
        
        int n = v.size();
        
        if(n == 0)                                                         return NULL;
        
        TreeNode* ans = convertBST(v, 0, n-1);
        return ans;
    }
};