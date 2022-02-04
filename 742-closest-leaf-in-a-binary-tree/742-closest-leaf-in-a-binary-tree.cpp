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
    
    unordered_map<int, vector<int>> adj;
    vector<int> vis, dist;                  // Dist[i] is distance from node k to node i
    
    vector<int> v;
    int maxNode = -1;
    
    vector<int> outdegree;
    int n = 0;
    
    void inorder(TreeNode* root) {
        
        if(root == NULL)                                    return;
        
        // inorder means left -> root -> right
        
        inorder(root->left);
        
        if(root->left != NULL) {
            
            // Make a undirected edge between root to root->left
            
            adj[root->val].push_back(root->left->val);
            outdegree[root->val]++;
            
            adj[root->left->val].push_back(root->val);
        }
        
        n++;
        
        v.push_back(root->val);
        maxNode = max(maxNode, root->val);
        
        if(root->right != NULL) {
          
            // Make a undirected edge between root to root->right
            
            adj[root->val].push_back(root->right->val);
            outdegree[root->val]++;
            
            adj[root->right->val].push_back(root->val);
        }
        
        inorder(root->right);
        
        return;
    }
    
    void bfs(int node) {
        
        // Run bfs from node "node"
        queue<int> q;
        
        q.push(node);
        
        dist[node] = 0;
        vis[node] = 1;
        
        while(q.empty() == false) {
           
            int temp = q.front();
            q.pop();

            for(int i=0; i<adj[temp].size(); i++) {
                
                int child = adj[temp][i];
                
                if(vis[child] == 0) {
                    
                    q.push(child);
                    
                    dist[child] = dist[temp] + 1;
                    vis[child] = 1;
                }
            }
        }
        
        return;
    }
    
    int findClosestLeaf(TreeNode* root, int k) {
    
        int mini = INT_MAX;                     // Min distance
        int res;                                // Closest leaf
    
        if(root == NULL)                                    return 0;
        if(root->left == NULL && root->right == NULL)       return root->val;
        
        // Find the closest leaf
        
        // Form the graph
        outdegree.resize(1001);
        inorder(root);
        
        // n is the no.of nodes from [1, maxNode]
        int e = n - 1;
        
        // A node is a leaf node if it has zero outdegree
        
        vis.resize(1001, 0);
        dist.resize(1001, 0);
        
        // Run bfs from node having value k to all nodes
        bfs(k);
        
        // for(int i=1; i<=maxNode; i++)                         cout << dist[i] << " ";
        // cout << endl;
        
        // for(int i=1; i<=maxNode; i++)                         cout << outdegree[i] << " ";
        // cout << endl;
        
        for(int i=1; i<=maxNode; i++) {
            
            // if node i is a leaf node, and if node i present in tree
            if(outdegree[i] == 0 && find(v.begin(), v.end(), i) != v.end()) {
                
                if(mini > dist[i]) {
                    mini = dist[i];
                    res = i;
                }
            }
        }
        
        return res;
    }
    
};