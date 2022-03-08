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
        
        while(head != NULL) {
            if(w.find(head) != w.end())                     return true;
            w.insert(head);
            head = head->next;
        }
        
        return false;
    }
    
};