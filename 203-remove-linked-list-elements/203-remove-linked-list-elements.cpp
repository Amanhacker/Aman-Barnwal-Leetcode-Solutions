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
    
    ListNode* removeElements(ListNode* head, int val) {
    
        // Remove all elements with value val
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        if(head == NULL)                                    return NULL;
        
        if(head->next == NULL) {
            
            if(head->val == val)                            return NULL;
            return head;
        }
        
        while(temp != NULL) {
            
            while(temp != NULL && temp->val != val) {
                prev = temp;
                temp = temp->next;
            }
           
            // Here, temp node contains the value val, so free temp
            if(temp != NULL && temp->val == val) {
                
                if(prev == NULL) {
                    head = temp->next;
                    temp = head;    
                }   

                else {
                    prev->next = temp->next;
                    temp = prev->next;
                }
            }
        }
        
        return head;
    }
    
};