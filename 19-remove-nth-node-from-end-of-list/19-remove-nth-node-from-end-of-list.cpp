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
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    
        int size = 0;
        
        ListNode* temp = head;
        
        while(temp != NULL) {
            temp = temp->next;
            size++;
        }
        
        int m = size - n;
        
        if(n == size)                           return head->next;
        
        // Remove mth node from beginning considering 0-based indexing
        
        int i = 0;
        
        ListNode* cur;
        temp = head;
        
        while(i < m && temp != NULL) {
            
            cur = temp;
            temp = temp->next;
            
            i++;
        }
        
        // Remove cur node
        
        if(temp == head)                        return NULL;
        
        cur->next = temp->next;
        return head;
    }
    
};