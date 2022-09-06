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
    
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
    
    void dfs(TreeNode* root, unordered_map<int, int> &u) {
        
        if(root == NULL)                                return;
        
        u[root->val]++;
        
        dfs(root->left, u);
        dfs(root->right, u);
        
        return;
    }
    
    vector<int> findMode(TreeNode* root) {
    
        vector<int> res;
        
        unordered_map<int, int> u;
        vector<pair<int, int>> v;
        
        dfs(root, u);
        
        for(auto &x : u)            v.push_back({x.first, x.second});
        sort(v.begin(), v.end(), cmp);
        
        auto it = v.begin();
        auto it1 = it + 1;
        
        int freq = it->second;
        res.push_back(it->first);
        
        while(it1 != v.end() && freq == it1->second) {
            res.push_back(it1->first);
            it1++;
        }    

        return res;
    }
    
};