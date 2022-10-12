/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void bfs(Node* &root) {
        
        if(root == NULL)                            return;
        
        queue<Node*> q;
        q.push(root);
        
        while(q.empty() == false) {
            
            int n = q.size();
            
            // Print all nodes at a level
            vector<Node*> path;
            
            while(n--) {
                
                Node* temp = q.front();
                q.pop();
            
                path.push_back(temp);
                
                if(temp->left != NULL)              q.push(temp->left);
                if(temp->right != NULL)             q.push(temp->right);
            }
            
            int k = path.size();
            
            for(int i=1; i<k; i++) {
                path[i-1]->next = path[i];
            }
            
            path[k-1]->next = NULL;
            
            path.clear();
        }
        
        return;
    }
    
    Node* connect(Node* root) {
        
        if(root == NULL)                        return NULL;
        
        bfs(root);
        return root;
    }
    
};