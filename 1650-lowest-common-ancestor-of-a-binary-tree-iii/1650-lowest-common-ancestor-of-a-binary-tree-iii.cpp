/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    
    Node* lowestCommonAncestor(Node* p, Node * q) {
    
        if(p == NULL || q == NULL)                 return NULL;
        
        Node* p1 = p;
        Node* q1 = q;
        
        while(p1 != q1) {
            
//             if(p1 != NULL)                          cout << "p1: " << p1->val << endl;
//             if(q1 != NULL)                          cout << "q1: " << q1->val << endl;
            
//             cout << "---" << endl;
            
            if(p1 == NULL)                            p1 = q;
            else                                      p1 = p1->parent;
            
            if(q1 == NULL)                            q1 = p;
            else                                      q1 = q1->parent;
        }        

        return p1;
    }
    
};