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
        
        ListNode* temp = new ListNode(val);
        
        if(head == NULL) {
            *head = temp;
            return;
        }
        
        else {
            temp->next = *head;
            *head = temp;
        }
        
        return;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    
        ListNode* head = NULL;
        vector<int> v;
        
        for(auto &x : lists) {
            
            ListNode* node = x;
            
            while(node != NULL) {
                v.push_back(node->val);
                node = node->next;
            }
        }
        
        sort(v.begin(), v.end(), greater<int>());
        
        for(auto &x : v) {
            addNodeAtBeginning(&head, x);
        }
        
        return head;
    }
    
};