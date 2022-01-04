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
    
    ListNode* deleteDuplicates(ListNode* head) {
    
        vector<int> v;
        
        ListNode* temp = head;
        
        while(temp != NULL) {
            if(find(v.begin(), v.end(), temp->val) == v.end())              v.push_back(temp->val);
            temp = temp->next;
        }
        
        reverse(v.begin(), v.end());
        ListNode* res = NULL;
        
        for(auto &x : v) {
            addNodeAtBeginning(&res, x);
        }
        
        
        return res;
    }
    
};