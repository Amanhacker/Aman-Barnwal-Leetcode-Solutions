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

    Node* dfs(Node* root) {
        
        if(root == NULL)                                return NULL;
        
        Node* newRoot = new Node(root->val);

        vector<Node*> ch = root->children;
        vector<Node*> newChild;
        
        for(auto &x : ch) {
            
            Node* temp = x;                 // temp is one of the children of root node
            Node* newTemp = dfs(temp);
            
            newChild.push_back(newTemp);
        }
        
        newRoot->children = newChild;
        return newRoot;
    }
    
    Node* cloneTree(Node* root) {
    
        Node* newRoot = NULL;
        
        newRoot = dfs(root);
        return newRoot;
    }
    
};