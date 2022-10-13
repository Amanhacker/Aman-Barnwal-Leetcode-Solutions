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
    
    void dfsGraph(int node, unordered_map<int, vector<int>> &adj, vector<int> &dist, vector<int> &vis, int &maxi, int d) {
        
        vis[node] = 1;
        dist[node] = d;
        
        for(auto &ch : adj[node]) {
            
            if(vis[ch] == 0) {
                
                dist[ch] = dist[node] + 1;
                maxi = max(maxi, dist[ch]);
                
                dfsGraph(ch, adj, dist, vis, maxi, d + 1);
            }
        }

        return;
    }
    
    void dfs(TreeNode* root, unordered_map<int, vector<int>> &adj) {
        
        if(root == NULL)                        return;
        
        if(root->left != NULL) {
            
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            
            dfs(root->left, adj);
        }   
        
        if(root->right != NULL) {
             
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            
            dfs(root->right, adj);            
        }   
        
        return;
    }
    
    int amountOfTime(TreeNode* root, int start) {
    
        int maxi = 0;
        
        // Form a graph
        
        unordered_map<int, vector<int>> adj;
        vector<int> dist(100001, 0), vis(100001, 0);
                         
        dfs(root, adj);
        
        dfsGraph(start, adj, dist, vis, maxi, 0);
        
        return maxi;
    }
    
};