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

    void findAllPaths(TreeNode* root, string temp, vector<string> &res) {
        
        if(root == NULL)                            return;
        
        temp += to_string(root->val);
        
        if(root->left == NULL && root->right == NULL) {
            res.push_back(temp);
        }
        
        else {
            temp += "->";
        }
        
        findAllPaths(root->left, temp, res);
        findAllPaths(root->right, temp, res);
        
        temp.pop_back();
        
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
    
        vector<string> res;
        
        if(root == NULL)                            return res;
        
        string temp = "";
        
        // Return all root to leaf paths
        findAllPaths(root, temp, res);
        return res;
    }
    
};