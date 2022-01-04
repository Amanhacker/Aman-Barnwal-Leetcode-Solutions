/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    bool hasCycle(ListNode *head) {
    
        set<ListNode*> w;
        
        ListNode* temp = head;
        
        while(temp != NULL) {
           
            if(w.find(temp) != w.end())                             return true;
            
            w.insert(temp);
            temp = temp->next;
        }
        
        return false;
    }
    
};