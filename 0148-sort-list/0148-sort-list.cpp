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
    
    // With O(1) space complexity

    void mergeList(ListNode* l1, ListNode* l2, ListNode** head) {
        
        ListNode* ptr = new ListNode(0);
        ListNode* cur = ptr;

        while(l1 != NULL && l2 != NULL) {

            if(l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }

            cur = cur->next;
        }

        if(l1 != NULL) {

            cur->next = l1;
            l1 = l1->next;
        }

        if(l2 != NULL) {

            cur->next = l2;
            l2 = l2->next;
        }

        *head = ptr->next;
        return;
    }

    ListNode* sortList(ListNode* head) {

        ListNode* newHead = NULL;   

        if(head == NULL || head->next == NULL)                     return head; 

        // Find the middle node of the Linked List
        ListNode* slow = head, *fast = head, *temp;

        while(fast != NULL && fast->next != NULL) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = NULL;      // End of 1st list

        // Here, slow is the middle node

        ListNode* l1 = sortList(head);    //    left half recursive call
        ListNode* l2 = sortList(slow);    //    right half recursive call

        mergeList(l1, l2, &newHead);

        return newHead;
    }

};