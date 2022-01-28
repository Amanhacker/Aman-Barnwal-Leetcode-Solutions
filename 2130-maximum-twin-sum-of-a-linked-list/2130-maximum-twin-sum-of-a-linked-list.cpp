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
    
    int pairSum(ListNode* head) {
    
        int res = INT_MIN;
        
        vector<int> v;
        
        while(head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }
        
        int n = v.size();
        
        for(int i=0, j=n-1; i<j; i++, j--)                                      res = max(res, v[i] + v[j]);
        
        return res;
    }
    
};