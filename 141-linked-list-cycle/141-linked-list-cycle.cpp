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
    
    bool hasCycle(ListNode *head) {
    
        set<ListNode*> w;
        
        if(head == NULL)                        return false;
        
        w.insert(head);
        
        while(head->next != NULL) {
            
            if(w.find(head->next) != w.end())   return true;
            
            w.insert(head->next);
            head = head->next;
        }
        
        return false;
    }
    
};