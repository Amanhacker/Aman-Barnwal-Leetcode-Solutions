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
    
    // Add node at beginning
    
    void addNodeAtBeginning(ListNode** head, int node) {
        
        ListNode* temp = new ListNode(node);
        
        if(head == NULL) {
            *head = temp;    
            return;
        }
        
        temp->next = *head;
        *head = temp;
        
        return;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
        ListNode* head = NULL;
        vector<int> v;
        
        while(list1 != NULL) {
            v.push_back(list1->val);
            list1 = list1->next;
        }
        
        while(list2 != NULL) {
            v.push_back(list2->val);
            list2 = list2->next;
        }
        
        sort(v.begin(), v.end(), greater<int>());
        
        for(auto &x : v) {
            addNodeAtBeginning(&head, x);      
        }
        
        return head;
    }
    
};