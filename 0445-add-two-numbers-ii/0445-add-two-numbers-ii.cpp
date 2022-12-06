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
    
    void addNodeAtBeginning(ListNode** head, int val) {

        ListNode* first = new ListNode(val);

        if(*head == NULL) {
            *head = first;
            return;
        }

        first->next = *head;
        *head = first;

        return;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = NULL;
        
        // Reverse both Linked Lists

        ListNode* cur1 = l1, *cur2 = l2;
        ListNode* prev = NULL, *next = NULL;

        while(cur1 != NULL) {
            
            next = cur1->next;
            cur1->next = prev;

            prev = cur1;
            cur1 = next;
        }

        l1 = prev;

        prev = NULL;
        next = NULL;

        while(cur2 != NULL) {
            
            next = cur2->next;
            cur2->next = prev;

            prev = cur2;
            cur2 = next;
        }

        l2 = prev;

        // Now, add two linked Lists
        int carry = 0;

        while(l1 != NULL && l2 != NULL) {
            
            int sum = l1->val + l2->val + carry;

            if(sum <= 9) {
                addNodeAtBeginning(&head, sum);
                cout << sum << " ";
                carry = 0;
            }

            else {
                addNodeAtBeginning(&head, sum % 10);
                cout << sum % 10 << " ";
                carry = sum / 10;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL) {
            
            int sum = l1->val + carry;

            if(sum <= 9) {
                addNodeAtBeginning(&head, sum);
                cout << sum << " ";
                carry = 0;
            }

            else {
                addNodeAtBeginning(&head, sum % 10);
                cout << sum % 10 << " ";
                carry = sum / 10;
            }
            
            l1 = l1->next;
        }

        while(l2 != NULL) {
            
            int sum = l2->val + carry;

            if(sum <= 9) {
                addNodeAtBeginning(&head, sum);
                cout << sum << " ";
                carry = 0;
            }

            else {
                addNodeAtBeginning(&head, sum % 10);
                cout << sum % 10 << " ";
                carry = sum / 10;
            }

            l2 = l2->next;
        }

        while(carry > 0) {
            addNodeAtBeginning(&head, carry % 10);
            cout << carry % 10 << " ";
            carry /= 10;
        }

        return head;
    }

};