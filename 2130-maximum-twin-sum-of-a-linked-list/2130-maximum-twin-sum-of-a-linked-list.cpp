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
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode* cur = head;
        
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        // Reverse the Linked List starting from (n / 2)th node in original Linked List
        while(cur != NULL) {
            
            next = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
    
    int pairSum(ListNode* head) {
    
        int res = INT_MIN;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // Here, fast becomes NULL and slow is (n/2)th node, considering 0-indexing
        // Now, reverse the Linked List after half nodes from index [n/2, n)
        
        ListNode* otherHead = reverseList(slow);
        
        while(otherHead != NULL) {
            
            res = max(res, otherHead->val + head->val);
            
            otherHead = otherHead->next;
            head = head->next;
        }
        
        return res;
    }
    
};