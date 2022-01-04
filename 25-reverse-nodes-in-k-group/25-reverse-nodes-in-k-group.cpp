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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
    
        if(head == NULL)                                            return NULL;
        
        ListNode* temp = head;
        int len = 0;
        
        vector<int> v;
        
        while(temp != NULL) {
            
            v.push_back(temp->val);
            temp = temp->next;
        
            len++;
        }
        
        int noOfGroups = len / k;
        
        // i is the groupNo
        for(int i=0; i<noOfGroups; i++) {
            
            // Range of a group is from [i*k, (i+1)*k)
            reverse(v.begin() + (i * k), v.begin() + (i + 1) * k);
        }
        
        reverse(v.begin(), v.end());
        
        ListNode* res = NULL;
        
        for(auto &x : v) {
            addNodeAtBeginning(&res, x);    
        }
        
        return res;
    }
    
};