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
    
    bool isPalindrome(ListNode* head) {
    
        if(head == NULL)                                    return false;
        
        ListNode* temp = head;
        string s = "";
        
        while(temp != NULL) {
            s += to_string(temp->val);
            temp = temp->next;
        }
        
        string str = s;
        reverse(s.begin(), s.end());
        
        return (str == s);
    }
    
};