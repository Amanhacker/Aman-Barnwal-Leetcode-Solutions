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
    
    vector<int> v;
    int n;
    
    Solution(ListNode* head) {
        
        while(head != NULL){
            v.push_back(head->val);
            head = head->next;
        }
        
        n = v.size();
    }
    
    int getRandom() {
        
        return v[rand() % n];
    }
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */