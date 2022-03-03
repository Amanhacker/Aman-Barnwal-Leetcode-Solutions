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
        
        if(root == NULL)                                return 0;
        
        int l = height(root->left);
        int r = height(root->right);
        
        return 1 + max(l, r);
    }
    
    void findLevelSum(TreeNode* root, int lev, double &count, double &sum) {
        
        if(root == NULL)                                return;
        
        if(lev == 1) {
            sum += (root->val);
            count++;
        }
        
        else if(lev > 1) {
            findLevelSum(root->left, lev - 1, count, sum);
            findLevelSum(root->right, lev - 1, count, sum);
        }
        
        return;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
    
        vector<double> res;
        
        int h = height(root);
        
        for(int i=1; i<=h; i++) {
            
            double count = 0, sum = 0;
            findLevelSum(root, i, count, sum);
            
            double avg = sum / count;
            res.push_back(avg);
        }
        
        return res;
    }
    
};