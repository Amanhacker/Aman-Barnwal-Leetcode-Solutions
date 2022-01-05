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
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
    
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        ListNode* res = NULL;
        
        vector<int> v;
        ListNode* temp = head;
        
        // Reverse the Linked List of even group length
        
        while(temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        // Now, v contains all the elements of Linked Lists
        // Now, reverse the even length group
        
        int n = v.size();
        
        // Rearrange the vector according to the question
        int groupNo = 0;
        
        for(int i=0; i<n; i += groupNo) {
            
            groupNo++;
            
            // GroupNo i contains i no.of nodes
            int noNodes = groupNo;
            
            // Node no ranges from [i, i + noNodes)
            
            // if last group should have greater length but length present is smaller than that
            if(i + noNodes - 1 >= n) {
               
                // Check whether length is even i.e element from [i, n)
                int lengthRemaining = (n - 1) - i + 1;
                
                if(lengthRemaining % 2 == 0) {
                    reverse(v.begin() + i, v.begin() + n);
                }
            }
            
            else if(noNodes % 2 == 0) {
                // Reverse the vector
                if(i + noNodes - 1 < n)          reverse(v.begin() + i, v.begin() + i + noNodes);
                else                             reverse(v.begin() + i, v.begin() + n);
            } 
            
        }
        
        ListNode* t = NULL;
        t = new ListNode(v[0]);
        
        res = t;    
        
        for(int i=1; i<n; i++) {
            
            ListNode* node = new ListNode(v[i]);
            t->next = node;
            
            t = node;
        }
        
        return res;
    }
    
};