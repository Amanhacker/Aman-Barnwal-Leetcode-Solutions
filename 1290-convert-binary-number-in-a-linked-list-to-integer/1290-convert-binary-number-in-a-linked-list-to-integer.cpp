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
    
    int getDecimalValue(ListNode* head) {
    
        ListNode* temp = head;
        string s = "";
        
        while(temp != NULL) {
            s += to_string(temp->val);
            temp = temp->next;
        }
        
        int n = s.length();
        int sum = 0;
        
        for(int i=n-1, j=0; i>=0; i--, j++) {
            if(s[i] == '1')                 sum += ((int)(s[i]) - 48) * pow(2, j);   
        }
        
        return sum;
    }
    
};