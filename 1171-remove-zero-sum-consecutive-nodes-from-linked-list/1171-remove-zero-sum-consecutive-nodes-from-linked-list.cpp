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
    
    ListNode* removeZeroSumSublists(ListNode* head) {
    
        ListNode* res = NULL;
        
        vector<int> v;
        ListNode* temp = head;
        
        while(temp != NULL) {
            if(temp->val != 0)                              v.push_back(temp->val);
            temp = temp->next;
        }
        
        int s = 0;
        for(auto &x : v)                                    s += x;
        
        if(s == 0)                                          return res;
        
        int i = 0, j = 1;
        
        // Remove those elements whose subarray sum is zero
        
        bool flag = true;
        
        while(flag == true) {
            
            if(v.size() == 0)                                                       return res;
            
            int n = v.size();
            
            for(int i=0; i<v.size()-1; i++) {
                for(int j=i+1; j<v.size(); j++) {

                    int sum = 0;

                    // Subarray is from index i to j
                    for(int k=i; k<=j; k++)                     sum += v[k];

                    if(sum == 0) {

                        // Erase elements from vector v from range [i, j]
                        int siz = j - i + 1;

                        while(siz--) {
                            v.erase(v.begin() + i);
                        }
                        
                        if(v.size() == 0)                                           return res;
                    }
                }
            }
            
            if(v.size() == 0)                                                       return res;
            
            // If after running 2 for loops, no element is deleted from vector, then come out of while loop
            if(n == v.size()) {
                flag = false;
                break;
            }
            
        }
        
        // Now, convert vector v into Linked List
        ListNode* t = new ListNode(v[0]);
        res = t;
        
        for(int i=1; i<v.size(); i++) {
            
            ListNode* node = new ListNode(v[i]);
            
            t->next = node;
            t = node;
        }
        
        return res;
    }
    
};