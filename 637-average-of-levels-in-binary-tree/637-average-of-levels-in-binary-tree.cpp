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
        
        int h = 0;
        
        if(root == NULL)                            return h;
        
        int left_h = height(root->left);
        int right_h = height(root->right);
        
        return 1 + max(left_h, right_h);
    }
    
    void findLevelOrder(TreeNode* root, int lev, int h, int &count, double &sum) {
        
        if(root == NULL)                            return;
        
        if(lev == 1) {
            
            sum += (double)(root->val);
            count++;
            
            return;
        }
        
        else if(lev > 1) {
            findLevelOrder(root->left, lev - 1, h, count, sum);
            findLevelOrder(root->right, lev - 1, h, count, sum);
        }
        
        return;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
    
        vector<double> res;
        
        if(root == NULL)                            return res;
        
        int h = height(root);
        
        for(int i=1; i<=h; i++) {
            
            int count = 0;
            double sum = 0;
            
            findLevelOrder(root, i, h, count, sum);
            
            double avg = sum / count;
            res.push_back(avg);
        }
        
        return res;
    }
    
};