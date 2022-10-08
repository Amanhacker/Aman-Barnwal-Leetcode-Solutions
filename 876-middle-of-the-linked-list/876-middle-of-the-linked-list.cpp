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
    
        if(head == NULL)                    return head;
        
        int len = 0;
        ListNode* t = head;
        
        while(t != NULL) {
            len++;
            t = t->next;
        }
        
        int midLen = len / 2;
        int i = 0;
        
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        
        while(i < midLen) {
            
            t1 = t1->next;
            t2 = t2->next;
            
            i++;    
        }
        
        return t1;
    }
    
};