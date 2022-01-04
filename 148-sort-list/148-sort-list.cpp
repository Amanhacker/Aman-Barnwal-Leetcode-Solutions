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
    
    ListNode* sortList(ListNode* head) {
    
        vector<int> v;
        
        ListNode* temp = head;
        
        while(temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        sort(v.begin(), v.end(), greater<int>());
        
        ListNode* res = NULL;
        
        for(auto &x : v) {
            addNodeAtBeginning(&res, x);
        }
        
        return res;
    }
    
};