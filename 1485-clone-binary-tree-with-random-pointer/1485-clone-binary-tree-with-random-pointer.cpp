/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    
    // Using map

    NodeCopy* helpCopyRandom(Node* root, unordered_map<Node*, NodeCopy*> &u) {
        
        if(root == NULL)                               return NULL;
        
        if(u.count(root))                              return u[root];
        
        NodeCopy* newRoot = new NodeCopy(root->val);
        u[root] = newRoot;
        
        newRoot->left   = helpCopyRandom(root->left, u);
        newRoot->right  = helpCopyRandom(root->right, u);
        newRoot->random = helpCopyRandom(root->random, u);
        
        return newRoot;
    }
    
    NodeCopy* copyRandomBinaryTree(Node* root) {
    
        NodeCopy* newRoot = NULL;
        
        if(root == NULL)                                return newRoot;
        
        unordered_map<Node*, NodeCopy*> u;              // 1st arg - Original Node, 2nd arg - Cloned Node
        
        newRoot = helpCopyRandom(root, u);
        return newRoot;
    }
    
};