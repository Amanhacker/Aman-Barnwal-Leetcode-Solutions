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
    
    ListNode* rotateRight(ListNode* head, int k) {
    
        if (head == NULL || head->next == NULL)                     return head;
        
        ListNode* temp = head;
        
        int len = 0;
        ListNode* prev = NULL;
        
        while (temp != NULL) {
            
            prev = temp;
            temp = temp->next;
            
            len++;
        }

        // Close the list (create a ring)
        temp = prev;
        
        temp->next = head;
        temp = head;
        
        
        // Find one element before the new head
        for(int i=0; i<len - (k % len) - 1; i++) {
            temp = temp->next;
        }
        
        head = temp->next;
        
        // Open the list (break the ring)
        temp->next = NULL;
        
        return head;
    }
    
};