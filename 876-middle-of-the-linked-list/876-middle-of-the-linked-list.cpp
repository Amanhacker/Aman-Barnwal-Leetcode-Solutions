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
    
    ListNode* middleNode(ListNode* head) {
    
        ListNode* t = head;
        
        if(head->next == NULL)                                  return head;
        
        // Using Slow and Fast Pointers
        
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // Here, slow node is one node before the middle node
        return slow->next;
    }
    
};