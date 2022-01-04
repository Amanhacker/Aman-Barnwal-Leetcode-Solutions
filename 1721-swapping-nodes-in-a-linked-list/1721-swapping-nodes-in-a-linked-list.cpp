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
    
    ListNode* swapNodes(ListNode* head, int k) {
    
        ListNode* res = head;
        
        if(res == NULL)                                          return res;
        
        // Swap kth node from beginning with kth node from end considering 1-indexing
        int len = 0;
        
        ListNode* t = head;
        
        while(t != NULL) {
            t = t->next;
            len++;
        }
        
        // (k - 1) node with (len - k) node
        int i = 0;
        ListNode* temp1 = head;
        
        while(i < k-1) {
            temp1 = temp1->next;
            i++;
        }
        
        // Here temp1 node is the 1st node which needs to be swapped
        i = 0;
        
        ListNode* temp2 = head;
        
        while(i < len-k) {
            temp2 = temp2->next; 
            i++;
        }
        
        // Now, swap temp1 node with temp2
        swap(temp1->val, temp2->val);
        
        return head;
    }
    
};