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
    
    int getDecimalValue(ListNode* head) {
    
        int sum = 0;
        ListNode* temp = head;
        
        while(temp != NULL) {
            sum = (sum * 2) + temp->val;
            temp = temp->next;
        }
        
        return sum;
    }
    
};