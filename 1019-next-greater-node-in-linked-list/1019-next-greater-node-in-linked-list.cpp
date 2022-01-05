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
    
    vector<int> nextLargerNodes(ListNode* head) {
    
        vector<int> res;
        ListNode* temp = head;
        
        vector<int> v;
        
        while(temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        // Now, find the next greater right of all elements of vector v
        stack<int> w;
        
        for(int i=v.size()-1; i>=0; i--) {
            
            if(w.empty() == true)                                       res.push_back(0);
            else if(w.top() > v[i])                                     res.push_back(w.top());
            else if(w.top() <= v[i]) {

                while(w.empty() == false && w.top() <= v[i])            w.pop();
                
                if(w.empty() == true)                                   res.push_back(0);
                else                                                    res.push_back(w.top());
            }
            
            w.push(v[i]);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
};