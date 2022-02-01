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
    
    map<int, map<int, vector<int>>> mp;

    // DFS Traversal
    void dfs(TreeNode* root, int row, int col) {
        
        if(root == NULL)                                               return;
        
        mp[col][row].push_back(root->val);
        
        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
        
        return;
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
    
        vector<vector<int>> res;
        
        if(root == NULL)                                                return res;
        
        // Find Vertical Order Traversal of the given BT
        dfs(root, 0, 0);
        
        for(auto &x : mp) {
            
            map<int, vector<int>> u = x.second;
            vector<int> temp;
            
            for(auto &x1 : u) {
                for(auto &x2 : x1.second)                              temp.push_back(x2);
            }
            
            res.push_back(temp);
            temp.clear();
        }
        
        return res;
    }
    
};