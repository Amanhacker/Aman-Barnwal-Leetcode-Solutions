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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
    TreeNode* convertBST(vector<int> v, int start, int end) {
        
        TreeNode* root = NULL;
        
        if(start > end)                                                    return NULL;
        
        int mid = start + (end - start) / 2;
        
        root = new TreeNode(v[mid]);
        
        root->left = convertBST(v, start, mid - 1);
        root->right = convertBST(v, mid + 1, end);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
    
        TreeNode* res = NULL;
        
        if(head == NULL)                                                    return res;
        
        vector<int> v;
        ListNode* temp = head;
        
        while(temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        // v contains element in ascending order
        
        // Convert it into height balanced BST
        
        int n = v.size();
        
        TreeNode* ans = convertBST(v, 0, n-1);
        
        return ans;
    }
    
};