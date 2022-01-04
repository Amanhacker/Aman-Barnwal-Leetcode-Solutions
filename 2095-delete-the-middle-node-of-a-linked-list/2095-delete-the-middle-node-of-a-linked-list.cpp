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
    
    ListNode* deleteMiddle(ListNode* head) {
    
        // If len of LL = 1, then return NULL
        if(head->next == NULL)                                      return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        // Slow pointer goes node-by-node, and fast pointer skips a node. 
        // When the fast node reaches the end, the slow node will point to the middle.
        
        while(fast != NULL && fast->next != NULL) {
            
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // Here, slow node is the one node before the middle node
        slow->next = slow->next->next;
       
        return head;
    }
    
};