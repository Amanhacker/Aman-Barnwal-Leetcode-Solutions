/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   
    // Reverse a Linked List
    void reverseLinkedList(ListNode** head) {
        
        ListNode* cur = *head;
        ListNode* temp = NULL;
        
        while(cur != NULL) {
            
            ListNode* t = cur->next;
            cur->next = temp;
            
            temp = cur;
            cur = t;
        }
        
        *head = temp;
        return;
    }
    
    // Add Node at Beginning of Linked List
    void addNodeAtBeginning(ListNode** head, int val) {
        
        ListNode* temp = new ListNode(val);
        
        if(head == NULL) {
            *head = temp;
            return;
        }
        
        else {
            temp->next = *head;
            *head = temp;
        }
        
        return;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
        ListNode* res = NULL;
        
        if(l1 == NULL && l2 == NULL)                                    return NULL;
        if(l1 == NULL)                                                  return l2;
        if(l2 == NULL)                                                  return l1;
        
        // Reverse both Linked List
        ListNode* res1 = NULL, *res2 = NULL;
        
        reverseLinkedList(&l1);
        reverseLinkedList(&l2);
        
        int carry = 0;
        
        while(l1 != NULL && l2 != NULL) {
            
            int val = l1->val + l2->val + carry;
            
            if(val >= 10) {
                carry = val / 10;
                val = val % 10;
            }
            
            else {
                carry = 0;
            }
            
            l1 = l1->next;
            l2 = l2->next;
            
            addNodeAtBeginning(&res, val);
        }
        
        while(l1 != NULL) {
            
            int val = l1->val + carry;
            
            if(val >= 10) {
                carry = val / 10;
                val = val % 10;
            }
            
            else {
                carry = 0;
            }
            
            l1 = l1->next;
            addNodeAtBeginning(&res, val);
        }
        
        while(l2 != NULL) {
            
            int val = l2->val + carry;
            
            if(val >= 10) {
                carry = val / 10;
                val = val % 10;
            }
            
            else {
                carry = 0;
            }
            
            l2 = l2->next;
            addNodeAtBeginning(&res, val);
        }
        
        if(carry > 0) {
            addNodeAtBeginning(&res, carry);
        }
        
        return res;
    }
    
};