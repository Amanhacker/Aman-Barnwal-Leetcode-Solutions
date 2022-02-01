/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    
    void inorder(Node* root, vector<int> &v) {
        
        if(root == NULL)                                            return;
        
        // inorder means left -> root -> right

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        
        return;
    }

    // It adds the node having value "data" at the end of Doubly Linked List
    void addNodeAtLast(Node** head, int data) {
        
        Node* temp = *head;

        while(temp->right != NULL) {
            temp = temp->right;
        }

        // Here, temp is the last node

        Node* last = new Node(data, NULL, NULL);

        temp->right = last;
        last->left = temp;

        return;
    }  
    
    Node* treeToDoublyList(Node* root) {
    
        Node* head = NULL;
        
        if(root == NULL)                                            return NULL;
        
        vector<int> v;
        
        inorder(root, v);
        int n = v.size();
        
        // Now, v contains all the nodes values in sorted order
        
        // Now, add each value at the end of doubly linked list
        // Here, right means next, and left means prev
        
        head = new Node(v[0], NULL, NULL);
        
        for(int i=1; i<n; i++) {
            addNodeAtLast(&head, v[i]);
        }
        
        // Now, make a connection between last and first node
        Node* temp = head;
        
        while(temp->right != NULL) {
            temp = temp->right;
        }
        
        // Here, temp is the last node
        temp->right = head;
        head->left = temp;
        
        return head;
    }
    
};