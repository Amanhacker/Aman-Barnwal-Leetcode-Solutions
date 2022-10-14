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
    

    vector<int> helper(TreeNode* root, int d, int &ans) {
        
        vector<int> res;
        
        if(root == NULL)                                    return {0};
        if(root->left == NULL && root->right == NULL)       return {1};
        
        vector<int> leftV = helper(root->left, d, ans);
        vector<int> rightV = helper(root->right, d, ans);
        
        for(auto &l : leftV) {
            for(auto &r : rightV) {
                if(l > 0 && r > 0 && l + r <= d)            ans++;
            }
        }
            
        for(auto &l : leftV) {
            if(l > 0 && l + 1 <= d)                          res.push_back(l + 1);
        }
        
        for(auto &r : rightV) {
            if(r > 0 && r + 1 <= d)                          res.push_back(r + 1);
        }
        
        return res;
    }
    
    int countPairs(TreeNode* root, int d) {
        
        int ans = 0;
        
        if(root == NULL)                        return ans;
        
        helper(root, d, ans);
        return ans;
    }
    
};