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
        
        if(res == NULL)                         return NULL;
        
        while(head != NULL && head->next != NULL) {
            
            ListNode* temp = head->next;
            swap(head->val, temp->val);
            
            head = temp->next;
        }
        
        return res;
    }
    
};