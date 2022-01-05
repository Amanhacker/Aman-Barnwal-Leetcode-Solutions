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
    
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    
        if(list1 == NULL)                                       return NULL;
        
        ListNode* res = list1;
        ListNode* temp = NULL;
        
        int i = 0;
        
        while(i < a) {
            temp = list1;
            list1 = list1->next;
            
            i++;
        }
        
        // Here, list1 node is the ath node
        
        while(i < b) {
            list1 = list1->next;
            i++;
        }
        
        ListNode* t = list1->next;
        
        // Here, list1 node is the bth node
        temp->next = list2;
        
        while(list2 ->next!= NULL) {
            list2 = list2->next;
        }
        
        // Here, list2 node is the last node of Linked List "list2"
        
        list2->next = t;
        
        return res;
    }
    
};