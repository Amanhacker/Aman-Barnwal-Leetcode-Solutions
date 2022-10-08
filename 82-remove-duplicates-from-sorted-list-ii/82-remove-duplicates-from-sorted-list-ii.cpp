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
    
    ListNode* deleteDuplicates(ListNode* head) {
    
        if(head == NULL)                            return NULL;
        
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        
        unordered_map<int, int> mp;
        
        while(t1 != NULL && t2 != NULL) {
            
            if(t1->val == t2->val)                  mp[t1->val] = 1;
            
            t1 = t1->next;
            t2 = t2->next;
        }
        
        t1 = head;
        t2 = head->next;
        
        while(t1 != NULL && t2 != NULL) {
            
            if(mp[t2->val] == 1) {
                t1->next = t2->next;    
                t2 = t1->next;
            }   
            
            else {
                t1 = t1->next;
                t2 = t2->next;
            }
        }
        
        if(mp[head->val] == 1)                      return head->next;
        
        return head;
    }
    
};