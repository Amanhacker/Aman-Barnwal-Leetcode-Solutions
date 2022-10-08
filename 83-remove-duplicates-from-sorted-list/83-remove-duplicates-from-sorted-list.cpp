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
   
    ListNode* deleteDuplicates(ListNode* head) {
    
        if(head == NULL)                        return NULL;
        
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        
        while(t1 != NULL && t2 != NULL) {
            
            if(t1->val == t2->val) {
                
                t1->next = t2->next;
                t2 = t1->next;
                
                if(t2 == NULL)                  return head;
            }
            
            else {
                t1 = t1->next;
                t2 = t2->next;
            }
        }
        
        return head;
    }
    
};