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
    
    void dfs(Node* root, vector<int> &res) {
        
        if(root == NULL)                        return;
        
        vector<Node*> ch = root->children;
        
        for(auto &x : ch) {
            Node* temp = x;
            dfs(temp, res);
        }
        
        res.push_back(root->val);
        
        return;
    }
    
    vector<int> postorder(Node* root) {
    
        vector<int> res;
        
        // Postorder means left -> right -> root
        dfs(root, res);
        
        return res;
    }
    
};