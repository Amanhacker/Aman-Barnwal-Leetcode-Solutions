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
        
        ListNode* t = new ListNode(reorderV[0]);
        res = t;
        
        for(int i=1; i<n; i++) {
            
            ListNode* node = new ListNode(reorderV[i]);
            
            t->next = node;
            t = node;
        }
        
        *head = *res;
        
        return;
    }
    
};