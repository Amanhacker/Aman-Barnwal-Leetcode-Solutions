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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    
        vector<int> v;
        
        ListNode* temp = head;
        
        while(temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        // Reverse the vector v in range [left-1, right-1]
        
        reverse(v.begin() + left - 1, v.begin() + right);
        
        reverse(v.begin(), v.end());
        ListNode* res = NULL;
        
        for(auto &x : v) {
            addNodeAtBeginning(&res, x);    
        }
        
        return res;
    }
    
};