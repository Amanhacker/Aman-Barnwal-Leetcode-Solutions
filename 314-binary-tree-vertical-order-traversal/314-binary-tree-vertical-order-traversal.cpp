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

    map<int, vector<int>> mp;

    // BFS Traversal using Queue
    
    void bfs(TreeNode* root) {
        
        if(root == NULL)                                              return;
        
        queue<pair<TreeNode*, int>> q;              // 1st arg - Node, 2nd arg - Column no
        q.push({root, 0});
        
        while(q.empty() == false) {
            
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            
            TreeNode* tempNode = temp.first;
            int colNo = temp.second;
            
            mp[colNo].push_back(tempNode->val);
            
            if(tempNode->left != NULL)                                 q.push({tempNode->left,  colNo - 1});
            if(tempNode->right != NULL)                                q.push({tempNode->right, colNo + 1});
        }
        
        return;
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if(root == NULL)                                                return res;
        
        // Find Vertical Order Traversal of the given BT
        bfs(root);
        
        for(auto &x : mp)                                               res.push_back(x.second);            
        
        return res;
    }
    
};