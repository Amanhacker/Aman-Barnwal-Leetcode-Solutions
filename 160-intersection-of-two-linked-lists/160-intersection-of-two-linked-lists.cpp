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
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
        set<ListNode*> w;
        
        while(headA != NULL) {
            w.insert(headA);
            headA = headA->next;
        }
        
        while(headB != NULL) {
            
            if(w.find(headB) != w.end()) {
                return headB;    
            }
            
            headB = headB->next;
        }
        
        return NULL;
    }
    
};