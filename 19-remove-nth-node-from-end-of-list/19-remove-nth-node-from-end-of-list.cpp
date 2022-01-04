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
    
        int len = 0;
        
        ListNode* t = head;
        
        while(t != NULL) {
            t = t->next;
            len++;
        }
        
        if(len == n) {
            return head->next;
        }
        
        // Removing nth node from end means removing (len - n)th node from beginning
        ListNode* temp = head;
        ListNode* prev = NULL;;
        
        int i = 0;
        
        while(i < len - n) {
            
            prev = temp;
            temp = temp->next;
            
            i++;
        }
        
        // Here, temp node needs to be deleted
        ListNode* t2 = temp->next;
        prev->next = t2;
        
        // free(temp);
        
        return head;
    }
    
};