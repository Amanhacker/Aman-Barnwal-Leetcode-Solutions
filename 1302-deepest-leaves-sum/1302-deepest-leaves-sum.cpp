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
   
    void bfs(TreeNode* root, int &sum) {
        
        if(root == NULL)                             return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false) {

            int n = q.size();
            int t = 0;
            
            for(int i=0; i<n; i++) {
                
                TreeNode* temp = q.front();
                q.pop();
                
                t += temp->val;
                
                if(temp->left != NULL)              q.push(temp->left);
                if(temp->right != NULL)             q.push(temp->right);
            }
            
            sum = t;
        }

        return;
    }
    
    int deepestLeavesSum(TreeNode* root) {
    
        if(root == NULL)                                            return 0;
        
        // Using level order traversal using Queue
        
        int sum = 0;
        bfs(root, sum);
        
        return sum;
    }
    
};