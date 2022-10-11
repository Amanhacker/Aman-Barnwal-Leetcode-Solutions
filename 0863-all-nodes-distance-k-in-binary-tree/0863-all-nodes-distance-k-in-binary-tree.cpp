/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    // Form the graph
    void bfs(TreeNode* root, unordered_map<int, vector<int>> &adj) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false) {
            
            int n = q.size();
            
            while(n--) {
                
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left != NULL) {
                    
                    adj[temp->left->val].push_back(temp->val);
                    adj[temp->val].push_back(temp->left->val);
                    
                    q.push(temp->left);
                }
                
                if(temp->right != NULL) {
                    
                    adj[temp->right->val].push_back(temp->val);
                    adj[temp->val].push_back(temp->right->val);
                    
                    q.push(temp->right);
                }
            }
        }
        
        return;
    }
   
    void dfs(int src, unordered_map<int, vector<int>> &adj, vector<int> &dist, vector<int> &vis) {
        
        vis[src] = 1;
        
        for(auto &ch : adj[src]) {
            
            if(vis[ch] == 0) {

                dist[ch] = dist[src] + 1;
                dfs(ch, adj, dist, vis);
                //cout << ch << " " << dist[ch] << endl;
            }
        }
        
        return;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    
        vector<int> res;
        unordered_map<int, vector<int>> adj;
        
        bfs(root, adj);
        int src = target->val;
        
        vector<int> dist(501, 0), vis(501, 0);
        dfs(src, adj, dist, vis);
        
        for(int i=0; i<=500; i++) {
            if(dist[i] == k && vis[i] == 1)                  res.push_back(i);
        }
        
        return res;
    }
    
};