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
    
    ListNode* partition(ListNode* head, int x) {
        
        // Create two nodes with garbage vales.

        // small -> to have nodes with value less than key
        // large -> to have nodes with value greater than or equal to key.

        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);

        // Now visit each node :

        // if node smaller -> add to small and small -> next = NULL
        // else -> add to large and large -> next = NULL

        ListNode *smallHead = small, *largeHead = large;

        while(head != NULL) {

            if(head->val < x) {
                
                small->next = head;
                small = small->next;
                
                head = head->next;
                small->next = NULL;
            }

            else {

                large->next = head;
                large = large->next;
                
                head = head->next;
                large->next = NULL;
            }
        }

        // At end, Join two Linked Lists [Remember the garbage nodes]

        // Make small->next = largeHead -> next : we appending largeHead -> next because the first node is garbage.

        small->next = largeHead->next;
        return smallHead->next;
    }
    
};