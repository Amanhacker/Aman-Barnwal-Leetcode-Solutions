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
    
        ListNode* temp = headA;
        set<ListNode*> w;
        
        while(temp != NULL) {
            w.insert(temp);
            temp = temp->next;
        }
        
        temp = headB;
        
        while(temp != NULL) {
            if(w.find(temp) != w.end())                         return temp;
            temp = temp->next;
        }
        
        return NULL;
    }
    
};