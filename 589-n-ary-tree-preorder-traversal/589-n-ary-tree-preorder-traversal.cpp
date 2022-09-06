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
    
    void preorderHelper(Node* root, vector<int> &res) {
        
        if(root == NULL)                    return;
        
        // preorder means root, left and right kind of order
        
        res.push_back(root->val);
        vector<Node*> ch = (root->children);
        
        for(auto &it : ch)                  preorderHelper(it, res);
        
        return;
    }
    
    vector<int> preorder(Node* root) {
    
        vector<int> res;
        
        if(root == NULL)                    return res;
        
        preorderHelper(root, res);
        
        return res;
    }
    
};