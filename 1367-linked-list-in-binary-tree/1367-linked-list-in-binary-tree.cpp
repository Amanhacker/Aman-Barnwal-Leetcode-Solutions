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
    
    bool isPath(ListNode* head, TreeNode* root) {
    
        if(head == NULL)                                    return true;
        if(root == NULL && head != NULL)                    return false;
        
        bool check;
        
        if(head->val == root->val)                          check = true;
        else                                                check = false;
        
        if(check == false)                                  return false;
        
        bool left  = isPath(head->next, root->left);
        bool right = isPath(head->next, root->right);
        
        return (left || right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
       
        if(root == NULL)                             return false;
        
        return isPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    
    
};