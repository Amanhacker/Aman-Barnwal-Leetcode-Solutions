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
    
    ListNode* middleNode(ListNode* head) {
    
        ListNode* t = head;
        
        int len = 0;
        
        while(t != NULL) {
            t = t->next;
            len++;
        }
        
        // Middle node is at position (len / 2), considering 0-based indexing
        int pos = len / 2;
        int i = 0;
        
        ListNode* temp = head;
        
        while(i < pos) {
            temp = temp->next;    
            i++;
        }
        
        // Here, temp node is the middle node
        return temp;
    }
    
};