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
    
    ListNode* swapPairs(ListNode* head) {
    
        ListNode* res = head;
        
        if(res == NULL)                                     return res;
        
        while(head != NULL && head->next != NULL) {
            
            ListNode* temp = head->next;
            swap(temp->val, head->val);
            
            ListNode* t2 = temp->next;
            head = t2;
        }
        
        return res;
    }
    
};