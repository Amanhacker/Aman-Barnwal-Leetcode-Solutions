/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map<Node*, Node*> u;

    Node* cloneGraph(Node* node) {
    
        if(node == NULL)                            return NULL;
        if(u.find(node) != u.end())                 return u[node];
        
        // Clone the graph
        
        Node* cloneNode = new Node(node->val, {});
        u[node] = cloneNode;
        
        for(Node* curNode : node->neighbors) {
            u[node]->neighbors.push_back(cloneGraph(curNode));
        }
        
        return cloneNode;
    }
};