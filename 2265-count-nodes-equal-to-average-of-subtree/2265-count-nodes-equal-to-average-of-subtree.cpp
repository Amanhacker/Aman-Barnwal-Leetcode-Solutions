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
    
    int countNodes(TreeNode* root, unordered_map<TreeNode*, int> &subtreeSize) {
        
        if(root == NULL)                    return 0;
        
        subtreeSize[root] = 1 + countNodes(root->left, subtreeSize) 
                            + countNodes(root->right, subtreeSize);
        
        return subtreeSize[root];
    }

    int totalSum(TreeNode* root, unordered_map<TreeNode*, int> &subtreeSum, vector<TreeNode*> &w) {
        
        if(root == NULL)                    return 0;
        
        w.push_back(root);
        
        subtreeSum[root] = root->val + totalSum(root->left, subtreeSum, w) 
                            + totalSum(root->right, subtreeSum, w);
        
        return subtreeSum[root];
    }
    
    int averageOfSubtree(TreeNode* root) {
    
        int ans = 0;
        
        if(root == NULL)                                        return ans;
        
        unordered_map<TreeNode*, int> subtreeSize, subtreeSum;
        countNodes(root, subtreeSize);
        
        vector<TreeNode*> w;
        totalSum(root, subtreeSum, w);
        
        for(auto &node : w) {
            if((int)(subtreeSum[node] / subtreeSize[node]) == node->val)                 ans++;
        }
        
        return ans;
    }
    
};