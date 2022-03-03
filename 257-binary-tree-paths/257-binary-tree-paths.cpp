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

    void dfs(TreeNode* root, vector<int> path, vector<string> &res) {
        
        if(root == NULL)                                return;
        
        path.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL) {
            
            string temp = "";
            int n = path.size();
            
            for(int i=0; i<path.size()-1; i++) {
                temp += to_string(path[i]);  
                temp += "->";
            }   
            
            temp += to_string(path[n-1]);
            res.push_back(temp);
        }
        
        dfs(root->left, path, res);
        dfs(root->right, path, res);
        
        path.pop_back();
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
    
        vector<string> res;
        
        vector<int> path;
        dfs(root, path, res);
        
        return res;
    }
    
};