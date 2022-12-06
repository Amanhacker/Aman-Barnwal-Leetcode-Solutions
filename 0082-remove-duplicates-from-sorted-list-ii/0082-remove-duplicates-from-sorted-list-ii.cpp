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
    
    // Using Sentinel Head
    
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL)                            return NULL;

        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;

        ListNode* temp = head, *prev = sentinel;

        while(temp != NULL) {
            
            if(temp->next != NULL && temp->val == temp->next->val) {
                
                // Move till the end of duplicates sublist
                while(temp->next != NULL && temp->val == temp->next->val) {
                    temp = temp->next;
                }
                
                // Skip all duplicates
                prev->next = temp->next;
            }
            else {
                prev = prev->next;
            }   

            temp = temp->next;
        }

        return sentinel->next;
    }

};