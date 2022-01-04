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
    
        ListNode* temp = head;
        set<ListNode*> w;
        
        while(temp != NULL) {
            
            if(w.find(temp) != w.end())                         return temp;
            
            w.insert(temp);
            temp = temp->next;
        }
        
        return NULL;
    }
    
};