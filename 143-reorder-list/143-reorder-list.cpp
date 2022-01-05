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
    
    void reorderList(ListNode* head) {
        
        // Base case 
        // if the size of Linked List <= 2 just return it
        
        if(head == NULL || head->next == NULL || head->next->next == NULL)                       return;
        
        // Find the Penultimate node i.e 2nd last node of the Linked List
        ListNode* penultimate = head;
        
        while(penultimate->next->next != NULL) {
            penultimate = penultimate->next;    
        }
        
        // Here, the penultimate node is 2nd last node of LL
        // Link the last element with the 2nd element from start
        
        // Here, last element is the penultimate->next
        penultimate->next->next = head->next;
        head->next = penultimate->next;
        
        // Again set the Penultimate as the last node i.e Set the last node to be NULL
        penultimate->next = NULL;
        
        // Do the above steps recursive
        reorderList(head->next->next);

        return;
    }
    
};