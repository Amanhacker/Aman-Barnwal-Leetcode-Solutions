/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void bfs(Node* root, vector<vector<int>> &res) {
        
        if(root == NULL)                            return;
        
        queue<Node*> q;
        q.push({root});
        
        while(q.empty() == false) {
            
            int n = q.size();
            vector<int> path;
            
            while(n--) {
                
                Node* temp = q.front();
                q.pop();
            
                path.push_back(temp->val);
                
                vector<Node*> ch = temp->children;
                
                for(auto &x : ch) {
                    q.push(x);
                }
            }
            
            res.push_back(path);
            path.clear();
        }
        
        return;
    }
    
    vector<vector<int>> levelOrder(Node* root) {
    
        vector<vector<int>> res;
        
        if(root == NULL)                            return res;
        
        bfs(root, res);
        return res;
    }
    
};