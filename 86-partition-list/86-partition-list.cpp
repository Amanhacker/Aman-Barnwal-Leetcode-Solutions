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
    
    ListNode* partition(ListNode* head, int node) {
    
        ListNode* res = NULL;
        
        vector<int> v;
        ListNode* temp = head;
        
        int count = 0;
        
        while(temp != NULL) {
            
            if(temp->val < node) {
                v.insert(v.begin() + count, temp->val);
                count++;
            }
            else {
                v.push_back(temp->val);                                
            }
            
            temp = temp->next;
        }
        
        reverse(v.begin(), v.end());
        
        for(auto &x : v) {
            addNodeAtBeginning(&res, x);
        }
        
        return res;
    }
};