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
    
    ListNode* rotateRight(ListNode* head, int k) {
    
        if(head == NULL)                                        return NULL;
        
        vector<int> v;
        
        ListNode* temp = head;
        
        while(temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        int n = v.size();
        
        k = k % n;
        vector<int> v1(n);
        
        // Rotate v to the right by k places
        for(int i=0; i<n; i++) {
            v1[(i+k+n) % n] = v[i];
        }        
        
        reverse(v1.begin(), v1.end());
        
        ListNode* res = NULL;
        
        for(auto &x : v1) {
           addNodeAtBeginning(&res, x);
        }
        
        return res;
    }
    
};