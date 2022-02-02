/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  
    Node* copyRandomList(Node* head) {
   
        Node* newHead;
        Node *l1, *l2;
        
        if(head == NULL)                                    return NULL;
        
        for(l1 = head; l1 != NULL; ) {
            
            l2 = new Node(l1->val);
            
            l2->next = l1->next;
            l1->next = l2;
            
            l1 = l1->next->next;
        }
        
        newHead = head->next;
        
        for(l1 = head; l1 != NULL; ) {
            
            if(l1->random != NULL)                          l1->next->random = l1->random->next;
            
            l1 = l1->next->next;
        }
        
        for(l1 = head; l1 != NULL; ) {
            
            l2 = l1->next;
            l1->next = l2->next;
            
            if(l2->next != NULL)                             l2->next = l2->next->next;
            
            l1 = l1->next;
        }
        
        return newHead;
    }
    
};