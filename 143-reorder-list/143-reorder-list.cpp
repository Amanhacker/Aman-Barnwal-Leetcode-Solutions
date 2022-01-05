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
    
    void reorderList(ListNode* head) {
    
        ListNode* res = NULL;
        
        vector<int> v, reorderV;
        ListNode* temp = head;
        
        while(temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        int n = v.size();
        int i, j;
        
        // Now, rearrange the vector
        for(i=0, j=n-1; i<j; i++, j--) {
            reorderV.push_back(v[i]);
            reorderV.push_back(v[j]);
        }
        
        if(i == j)                                       reorderV.push_back(v[i]);
        
        reverse(reorderV.begin(), reorderV.end());
        
        for(auto &x : reorderV) {
            addNodeAtBeginning(&res, x);
        }
        
        *head = *res;
        
        return;
    }
    
};