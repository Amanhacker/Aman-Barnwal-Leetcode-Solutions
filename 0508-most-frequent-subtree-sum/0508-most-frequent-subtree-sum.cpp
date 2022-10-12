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
    
    void findSubtreeSum(TreeNode* root, int &sum) {
        
        if(root == NULL)                            return;
        
        sum += root->val;
        
        findSubtreeSum(root->left, sum);
        findSubtreeSum(root->right, sum);
        
        return;
    }
    
    void dfs(TreeNode* root, unordered_map<int, int> &u) {
        
        if(root == NULL)                            return;
        
        int sum = 0;
        findSubtreeSum(root, sum);
        
        u[sum]++;
        
        dfs(root->left, u);
        dfs(root->right, u);
        
        return;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
    
        vector<int> res;
        
        if(root == NULL)                            return res;
        
        // 1st arg - sum, 2nd arg - Freq
        unordered_map<int, int> u;      
        
        // Find subtree sum at each node
        dfs(root, u);
        
        int maxFreq = -1;
        
        // 1st arg - Freq, 2nd arg - vector of Sum
        unordered_map<int, vector<int>> mp;
        
        for(auto &x : u) {
            
            if(maxFreq <= x.second) {
                maxFreq = x.second;
                mp[maxFreq].push_back(x.first);        
            }
        }
        
        res = mp[maxFreq];
        return res;
    }
    
};