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
    
    void postorderHelper(Node* root, vector<int> &res) {
        
        if(root == NULL)                        return;
        
        // postorder means left -> right -> root
        
        vector<Node*> ch = root->children;
        
        for(auto it : ch) {
            postorderHelper(it, res);
        }
        
        res.push_back(root->val);
        return;
    }
    
    vector<int> postorder(Node* root) {
    
        vector<int> res;
        
        if(root == NULL)                        return res;
        
        postorderHelper(root, res);
        return res;
    }
    
};