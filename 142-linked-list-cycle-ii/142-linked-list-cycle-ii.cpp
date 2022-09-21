/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode *detectCycle(ListNode *head) {
    
        ListNode* res = NULL;
        
        if(head == NULL)                    return NULL;
        
        set<ListNode*> w;
        w.insert(head);
        
        while(head->next != NULL) {
            
            if(w.find(head->next) != w.end()) {
                return head->next;
            }
            
            w.insert(head);
            head = head->next;
        }
        
        return res;
    }
    
};