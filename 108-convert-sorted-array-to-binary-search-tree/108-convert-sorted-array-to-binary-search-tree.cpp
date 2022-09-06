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
    
    TreeNode* sortedArrayToBSTHelper(vector<int> &nums, int start, int end) {
        
        TreeNode* root = NULL;
        
        if(start > end)                                          return root;
        
        int mid = start + (end - start)/2;
        
        root = new TreeNode(nums[mid]);
        
        // Form two subtree, one from [0, mid - 1], and 2nd from [mid + 1, n - 1]
        root->left = sortedArrayToBSTHelper(nums, start,  mid - 1);
        root->right = sortedArrayToBSTHelper(nums, mid + 1, end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    
        if(nums.size() == 0)                               return NULL;
        
        int n = nums.size();
                
        return sortedArrayToBSTHelper(nums, 0, n - 1);
    }
    
};