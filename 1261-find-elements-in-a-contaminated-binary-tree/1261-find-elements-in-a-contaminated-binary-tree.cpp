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
class FindElements {
public:
    
    unordered_map<int, int> u;          // 1st arg- value, 2nd arg - Present or not
    
    void preorder(TreeNode* &root, int data) {
        
        if(root == NULL)                                return;
        
        root->val = data;
        u[data]++;
        
        preorder(root->left, 2*data + 1);
        preorder(root->right, 2*data + 2);
        
        return;
    }
    
    FindElements(TreeNode* root) {
     
        // Convert the contaminated BT to required BT
        
        // if root->val = x, then value of its left children is 2*x + 1, and that of right children is 2*x + 2
        
        // root -> left -> right
        int data = 0;
        preorder(root, data);
        
    }
    
    bool find(int target) {
    
        return (u[target] >= 1);
    }
    
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */