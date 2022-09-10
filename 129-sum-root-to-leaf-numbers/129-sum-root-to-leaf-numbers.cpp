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
    
    long long int sumPath(vector<int> path) {
        
        int t = 0, n = path.size();
        long long int mul = 1;
        
        for(int i=n-1; i>=0; i--) {
            t += (mul * path[i]);
            mul *= 10;    
        }   
        
        return t;
    }
    
    void findAllPaths(TreeNode* root, int &sum, vector<int> path) {
        
        if(root == NULL)                    return;
        
        path.push_back(root->val);
        
        // If found a leaf node
        if(root->left == NULL && root->right == NULL) {
            sum += sumPath(path);
        }
        
        findAllPaths(root->left, sum, path);
        findAllPaths(root->right, sum, path);
        
        path.pop_back();
        return;
    }
    
    int sumNumbers(TreeNode* root) {
    
        int sum = 0;
        
        // Print all root to leaf
        if(root == NULL)                    return sum;
        
        vector<int> path;
        findAllPaths(root, sum, path);
        
        return sum;
    }
    
};